#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord;

    TrieNode() : isWord(false), children(unordered_map<char, TrieNode*>()) {}
};

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (string word : wordDict) {
            TrieNode* curr = root;
            for (char c : word) {
                if (curr->children.find(c) == curr->children.end()) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->isWord = true;
        }


        int n = s.length();
        vector<bool> memo(n, false);
        for(int i = 0; i < n; i++) {
            if (i == 0 || memo[i - 1]) {
                TrieNode* curr = root;
                for (int j = i; j < n; j++) {
                    if (curr->children.find(s[j]) == curr->children.end()) {
                        break;
                    }
                    curr = curr->children[s[j]];
                    if (curr->isWord) {
                        memo[j] = true;
                    }
                }
            }
        }
        return memo[n - 1];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }
    string s;
    cin >> s;

    Solution sol;
    bool result = sol.wordBreak(s, wordDict);
    cout << (result ? "true" : "false") << "\n";

    return 0;
}