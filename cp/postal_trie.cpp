/**
 * postal_trie.cpp — Pincode Trie Engine
 *
 * Compile:  g++ -std=c++17 -O2 -o postal_trie postal_trie.cpp
 * Run:      ./postal_trie
 *
 * Operations  (all O(6) = O(1)):
 *   insert(code)         — add a pincode
 *   remove(code)         — block/delete a pincode
 *   contains(code)       — membership test
 *   toRegex()            — compact regex from current trie
 *   toPincodeList()      — sorted list of all stored pincodes
 *   toReadable()         — human-readable ranges  e.g. 110001-110003, 110010
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// ─────────────────────────────────────────────────────────────────────────────
//  Constants
// ─────────────────────────────────────────────────────────────────────────────

static constexpr int DIGITS = 6;   // pincode length
static constexpr int BR     = 10;  // branching factor (digits 0-9)

// ─────────────────────────────────────────────────────────────────────────────
//  Node
// ─────────────────────────────────────────────────────────────────────────────

struct Node {
    std::array<std::unique_ptr<Node>, BR> ch{};
    int nch = 0;   // number of non-null children
    int end = 0;   // >0 → a complete pincode terminates here
};

// ─────────────────────────────────────────────────────────────────────────────
//  Digit helpers
// ─────────────────────────────────────────────────────────────────────────────

static std::array<int,DIGITS> toDigits(int v) {
    std::array<int,DIGITS> d{};
    for (int i = DIGITS-1; i >= 0; --i) { d[i] = v % 10; v /= 10; }
    return d;
}

static int fromDigits(const std::array<int,DIGITS>& d) {
    int v = 0;
    for (int x : d) v = v*10 + x;
    return v;
}

static bool isValid(int code) { return code >= 100000 && code <= 999999; }

// ─────────────────────────────────────────────────────────────────────────────
//  Compact character class for a set of present digits
//  (mirrors Haskell's truncateLeafNodesRegexList)
//
//  Priority:
//    all 10 digits          →  [\d]
//    >3 contiguous          →  [a-b]
//    missing < present      →  [^ab] or [^a-b]
//    default                →  [ab]
// ─────────────────────────────────────────────────────────────────────────────

static std::string digitClass(const std::vector<int>& p) {
    int n = (int)p.size();
    if (n == 0)  return "";
    if (n == 10) return "[\\d]";

    // check contiguous run
    auto isCont = [](const std::vector<int>& v) {
        for (int i = 1; i < (int)v.size(); ++i)
            if (v[i] != v[i-1]+1) return false;
        return true;
    };

    if (n > 3 && isCont(p))
        return "[" + std::to_string(p.front()) + "-" + std::to_string(p.back()) + "]";

    // build missing set
    std::vector<int> miss;
    for (int d = 0, pi = 0; d < 10; ++d)
        if (pi < n && p[pi] == d) ++pi;
        else miss.push_back(d);

    int m = (int)miss.size();
    if (m < n) {
        if (m > 3 && isCont(miss))
            return "[^" + std::to_string(miss.front()) + "-" + std::to_string(miss.back()) + "]";
        std::string s = "[^";
        for (int x : miss) s += std::to_string(x);
        return s + "]";
    }

    std::string s = "[";
    for (int x : p) s += std::to_string(x);
    return s + "]";
}

// ─────────────────────────────────────────────────────────────────────────────
//  Trie operations
// ─────────────────────────────────────────────────────────────────────────────

// Insert — returns false if already present
static bool insert(Node* node, const std::array<int,DIGITS>& d, int depth) {
    if (depth == DIGITS) {
        if (node->end) return false;
        node->end = 1;
        return true;
    }
    int digit = d[depth];
    if (!node->ch[digit]) { node->ch[digit] = std::make_unique<Node>(); node->nch++; }
    return insert(node->ch[digit].get(), d, depth+1);
}

// Remove — returns true if node is now empty (prune signal)
static bool remove(Node* node, const std::array<int,DIGITS>& d, int depth, bool& found) {
    if (!node) return false;
    if (depth == DIGITS) {
        if (node->end) { node->end = 0; found = true; }
        return !node->end && node->nch == 0;
    }
    int digit = d[depth];
    if (!node->ch[digit]) return false;
    if (remove(node->ch[digit].get(), d, depth+1, found)) {
        node->ch[digit].reset();
        node->nch--;
    }
    return node->nch == 0 && !node->end;
}

// Collect all pincodes via DFS
static void collect(const Node* node, int depth,
                    std::array<int,DIGITS>& buf, std::vector<int>& out) {
    if (!node) return;
    if (depth == DIGITS) { if (node->end) out.push_back(fromDigits(buf)); return; }
    for (int d = 0; d < BR; ++d) {
        if (node->ch[d]) { buf[depth] = d; collect(node->ch[d].get(), depth+1, buf, out); }
    }
}

// Build regex fragment for subtrie rooted at node
static std::string buildRegex(const Node* node) {
    if (!node || node->nch == 0) return "";

    std::vector<int>         present;
    std::vector<std::string> sub;

    for (int d = 0; d < BR; ++d) {
        if (!node->ch[d]) continue;
        present.push_back(d);
        sub.push_back(buildRegex(node->ch[d].get()));
    }

    // All children share the same sub-regex → compress to a character class
    bool allSame = std::all_of(sub.begin(), sub.end(),
                               [&](const std::string& s){ return s == sub[0]; });
    if (allSame) {
        if (present.size() == 1) return std::to_string(present[0]) + sub[0];
        return digitClass(present) + sub[0];
    }

    // Different sub-regexes → alternation group
    std::string s;
    for (int i = 0; i < (int)present.size(); ++i) {
        if (i) s += '|';
        s += std::to_string(present[i]) + sub[i];
    }
    return "(" + s + ")";
}

// ─────────────────────────────────────────────────────────────────────────────
//  PostalTrie — public API
// ─────────────────────────────────────────────────────────────────────────────

class PostalTrie {
    std::unique_ptr<Node> root = std::make_unique<Node>();

public:
    // add a pincode (returns false if duplicate)
    bool insert(int code) {
        if (!isValid(code)) throw std::invalid_argument("invalid pincode");
        return ::insert(root.get(), toDigits(code), 0);
    }
    void insert(const std::vector<int>& codes) { for (int c : codes) insert(c); }

    // block / remove a pincode (returns false if not present)
    bool remove(int code) {
        if (!isValid(code)) return false;
        bool found = false;
        ::remove(root.get(), toDigits(code), 0, found);
        return found;
    }
    void remove(const std::vector<int>& codes) { for (int c : codes) remove(c); }

    // membership check
    bool contains(int code) const {
        if (!isValid(code)) return false;
        auto d = toDigits(code);
        const Node* cur = root.get();
        for (int i = 0; i < DIGITS; ++i) {
            if (!cur->ch[d[i]]) return false;
            cur = cur->ch[d[i]].get();
        }
        return cur->end > 0;
    }

    // compact regex:  ^<pattern>$  or "" if empty
    std::string toRegex() const {
        if (!root->nch) return "";
        return "^" + buildRegex(root.get()) + "$";
    }

    // sorted list of all stored pincodes
    std::vector<int> toList() const {
        std::vector<int> out;
        std::array<int,DIGITS> buf{};
        collect(root.get(), 0, buf, out);
        std::sort(out.begin(), out.end());
        return out;
    }

    // human-readable: contiguous runs collapsed to ranges
    std::string toReadable() const {
        auto v = toList();
        if (v.empty()) return "(empty)";
        std::ostringstream oss;
        for (size_t i = 0; i < v.size(); ) {
            size_t j = i;
            while (j+1 < v.size() && v[j+1] == v[j]+1) ++j;
            if (i > 0) oss << ", ";
            if (j > i) oss << v[i] << "-" << v[j];
            else        oss << v[i];
            i = j+1;
        }
        return oss.str();
    }

    bool empty() const { return root->nch == 0; }
    int  size()  const { return (int)toList().size(); }
};

// ─────────────────────────────────────────────────────────────────────────────
//  Demo / tests
// ─────────────────────────────────────────────────────────────────────────────

static void show(const PostalTrie& t) {
    std::cout << "  regex    : " << (t.empty() ? "(empty)" : t.toRegex()) << "\n";
    std::cout << "  readable : " << t.toReadable() << "\n";
    auto v = t.toList();
    std::cout << "  list     : ";
    for (size_t i = 0; i < std::min(v.size(), size_t(12)); ++i) {
        if (i) std::cout << ", ";
        std::cout << v[i];
    }
    if (v.size() > 12) std::cout << " … (" << v.size() << " total)";
    std::cout << "\n";
}

static void section(const char* s) {
    std::cout << "\n── " << s << " ──\n";
}

int main() {
    // 1. build from list
    section("1  build from list");
    PostalTrie t;
    t.insert({110001, 110002, 110003, 110010, 400001, 400002, 560001});
    show(t);

    // 2. add more
    section("2  add 560002, 560003");
    t.insert(560002); t.insert(560003);
    show(t);

    // 3. block / remove
    section("3  block 110002");
    std::cout << "  remove(110002) -> " << (t.remove(110002) ? "ok" : "not found") << "\n";
    show(t);

    std::cout << "  remove(999999) -> " << (t.remove(999999) ? "ok" : "not found") << "\n";

    // 4. membership
    section("4  contains");
    for (int c : {110001, 110002, 400001, 999999})
        std::cout << "  " << c << " -> " << (t.contains(c) ? "yes" : "no") << "\n";

    // 5. dense range readable
    section("5  dense range 110001-110050 + 110100-110102");
    PostalTrie t2;
    for (int c = 110001; c <= 110050; ++c) t2.insert(c);
    t2.insert({110100, 110101, 110102});
    show(t2);

    // 6. leaf compression showcase
    section("6a  110000-110009  → [\\d]");
    PostalTrie t3;
    for (int d = 0; d <= 9; ++d) t3.insert(110000+d);
    show(t3);

    section("6b  110001-110005  → [1-5]");
    PostalTrie t4;
    for (int d = 1; d <= 5; ++d) t4.insert(110000+d);
    show(t4);

    section("6c  110001,110002,110008,110009  → [^3-7] or [^345670]");
    PostalTrie t5;
    for (int d : {1,2,8,9}) t5.insert(110000+d);
    show(t5);

    // 7. suffix factoring
    section("7  suffix factoring: 110001 and 220001");
    PostalTrie t6;
    t6.insert({110001, 220001});
    show(t6);

    // 8. duplicate / invalid
    section("8  duplicate + invalid");
    PostalTrie t7; t7.insert(110001);
    std::cout << "  dup insert -> " << (t7.insert(110001) ? "inserted" : "duplicate (ignored)") << "\n";
    try   { t7.insert(99999); }
    catch (const std::exception& e) { std::cout << "  invalid   -> caught: " << e.what() << "\n"; }

    // 9. round-trip stress test
    section("9  round-trip: 500 codes");
    PostalTrie t8;
    std::vector<int> orig;
    for (int i = 0; i < 500; ++i) {
        int code = 100000 + (i * 1973 % 900000);
        if (t8.insert(code)) orig.push_back(code);
    }
    std::sort(orig.begin(), orig.end());
    auto got = t8.toList();
    std::cout << "  inserted  : " << orig.size() << "\n";
    std::cout << "  recovered : " << got.size() << "\n";
    std::cout << "  match     : " << (orig == got ? "YES ✓" : "NO ✗") << "\n";
    std::cout << "  regex len : " << t8.toRegex().size() << " chars\n";

    return 0;
}