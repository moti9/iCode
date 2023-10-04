#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
    int open, close, full;
    Node() : open(0), close(0), full(0) {}
    Node(int _open, int _close, int _full) : open(_open), close(_close), full(_full) {}
};

class SegmentTree
{
    vector<Node *> segment;

public:
    SegmentTree(int n)
    {
        segment.resize(4 * n);
    }

    Node *mergeSegments(Node *left, Node *right)
    {
        Node *node = new Node();
        node->full = left->full + right->full + min(left->open, right->close);
        node->open = left->open + right->open - min(left->open, right->close);
        node->close = left->close + right->close - min(left->open, right->close);
        return node;
    }

    void build(int ind, int low, int high, const string &s)
    {
        if (low == high)
        {
            if (s[low] == '(')
                segment[ind] = new Node(1, 0, 0);
            else
                segment[ind] = new Node(0, 1, 0);
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, s);
        build(2 * ind + 2, mid + 1, high, s);
        segment[ind] = mergeSegments(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    Node *query(int ind, int low, int high, int l, int r)
    {
        if (r < low || high < l)
            return new Node(0, 0, 0);
        if (low >= l && high <= r)
            return segment[ind];
        int mid = (low + high) >> 1;
        Node *left = query(2 * ind + 1, low, mid, l, r);
        Node *right = query(2 * ind + 2, mid + 1, high, l, r);
        return mergeSegments(left, right);
    }

    ~SegmentTree()
    {
        for (Node *node : segment)
            delete node;
    }
};

class Solution
{
public:
    Solution()
    {
        string s;
        cin >> s;
        int n = s.length();
        SegmentTree seg(n);
        seg.build(0, 0, n - 1, s);
        int q;
        cin >> q;
        Node *ansNode = new Node(0, 0, 0);
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            ansNode = seg.query(0, 0, n - 1, l, r);
            cout << ansNode->full * 2 << "\n";
        }
        delete ansNode;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll ttt = 1;
    while (ttt--)
    {
        Solution moti;
    }
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
public:
    int open, close, full;
    Node()
    {
        open = 0, close = 0, full = 0;
    }
    Node(int _open, int _close, int _full)
    {
        open = _open;
        close = _close;
        full = _full;
    }
};

class SegmentTree
{
    vector<Node> segment;

public:
    SegmentTree(int n)
    {
        segment.resize(4 * n);
    }

    Node mergeSegments(Node &left, Node &right)
    {
        Node node;
        node.full = left.full + right.full + min(left.open, right.close);
        node.open = left.open + right.open - min(left.open, right.close);
        node.close = left.close + right.close - min(left.open, right.close);
        return node;
    }

    void build(int ind, int low, int high, string &s)
    {
        if (low == high)
        {
            if (s[low] == '(')
            {
                Node node(1, 0, 0);
                segment[ind] = node;
            }
            else
            {
                Node node(0, 1, 0);
                segment[ind] = node;
            }
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, s);
        build(2 * ind + 2, mid + 1, high, s);
        segment[ind] = mergeSegments(segment[2 * ind + 1], segment[2 * ind + 2]);
    }
    Node query(int ind, int low, int high, int l, int r)
    {
        if (r < low || high < l)
        {
            Node node(0, 0, 0);
            return node;
        }
        if (low >= l && high <= r)
        {
            return segment[ind];
        }
        int mid = (low + high) >> 1;
        Node left = query(2 * ind + 1, low, mid, l, r);
        Node right = query(2 * ind + 2, mid + 1, high, l, r);
        return mergeSegments(left, right);
    }
};

class solution
{
public:
    solution()
    {
        string s;
        cin >> s;
        int n = s.length();
        SegmentTree seg(n);
        seg.build(0, 0, n - 1, s);
        int q;
        cin >> q;
        Node ansNode(0, 0, 0);
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            ansNode = seg.query(0, 0, n - 1, l, r);
            cout << ansNode.full * 2 << "\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        solution moti;
    }
    return 0;
}
*/
