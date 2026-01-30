#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Node
{
public:
    int openBrackets;
    int closeBrackets;
    int completePairs;
    Node()
    {
        openBrackets = 0;
        closeBrackets = 0;
        completePairs = 0;
    }

    Node(int open, int close, int pairs)
    {
        openBrackets = open;
        closeBrackets = close;
        completePairs = pairs;
    }
};

class SegmentTree
{
    Node mergeNodes(Node &leftNode, Node &rightNode)
    {
        Node parentNode;
        int matchedPairs = min(leftNode.openBrackets, rightNode.closeBrackets);
        parentNode.completePairs = leftNode.completePairs + rightNode.completePairs + matchedPairs;
        parentNode.openBrackets = leftNode.openBrackets + rightNode.openBrackets - matchedPairs;
        parentNode.closeBrackets = leftNode.closeBrackets + rightNode.closeBrackets - matchedPairs;
        return parentNode;
    }
public:
    vector<Node> segTree;
    SegmentTree(int n)
    {
        segTree.resize(4 * n);
    }

    void buildSegmentTree(int index, int left, int right, string &s)
    {
        if (left == right)
        {
            if (s[left] == '(')
            {
                segTree[index] = Node(1, 0, 0);
            }
            else
            {
                segTree[index] = Node(0, 1, 0);
            }
            return;
        }
        int mid = (left + right) / 2;
        buildSegmentTree(2 * index + 1, left, mid, s);
        buildSegmentTree(2 * index + 2, mid + 1, right, s);
        segTree[index] = mergeNodes(segTree[2 * index + 1], segTree[2 * index + 2]);
    }

    Node querySegmentTree(int index, int left, int right, int ql, int qr)
    {
        if (ql > right || qr < left)
        {
            return Node();
        }
        if (ql <= left && qr >= right)
        {
            return segTree[index];
        }
        int mid = (left + right) / 2;
        Node leftSum = querySegmentTree(2 * index + 1, left, mid, ql, qr);
        Node rightSum = querySegmentTree(2 * index + 2, mid + 1, right, ql, qr);
        return mergeNodes(leftSum, rightSum);
    }

};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int m;
    cin >> m;
    int n = s.length();
    SegmentTree segTree(n);
    segTree.buildSegmentTree(0, 0, n - 1, s);

    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        Node ans = segTree.querySegmentTree(0, 0, n - 1, l, r);
        cout << ans.completePairs * 2 << "\n";
    }

    return 0;
}