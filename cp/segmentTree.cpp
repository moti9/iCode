#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class SegmentTree
{
    private:
        vector<int> segTree;
public:
    SegmentTree(int n)
    {
        segTree.resize(4 * n, INT_MAX);
    }

    void buildSegmentTree(int index, int left, int right, int arr[])
    {
        if (left > right)
            return;
        if (left == right)
        {
            segTree[index] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        buildSegmentTree(2 * index + 1, left, mid, arr);
        buildSegmentTree(2 * index + 2, mid + 1, right, arr);
        segTree[index] = min(segTree[2 * index + 1], segTree[2 * index + 2]);
    }

    int queryMin(int index, int left, int right, int queryLeft, int queryRight)
    {
        if (queryRight < left || queryLeft > right)
        {
            return INT_MAX;
        }
        if (queryLeft <= left && queryRight >= right)
        {
            return segTree[index];
        }
        int mid = (left + right) / 2;
        int leftMin = queryMin(2 * index + 1, left, mid, queryLeft, queryRight);
        int rightMin = queryMin(2 * index + 2, mid + 1, right, queryLeft, queryRight);
        return min(leftMin, rightMin);
    }

    void updateSegmentTree(int index, int left, int right, int pos, int newVal)
    {
        if (left == right)
        {
            segTree[index] = newVal;
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid)
        {
            updateSegmentTree(2 * index + 1, left, mid, pos, newVal);
        }
        else
        {
            updateSegmentTree(2 * index + 2, mid + 1, right, pos, newVal);
        }
        segTree[index] = min(segTree[2 * index + 1], segTree[2 * index + 2]);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegmentTree segTree(n);
    segTree.buildSegmentTree(0, 0, n - 1, arr);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << segTree.queryMin(0, 0, n - 1, l, r) << "\n";
        }
        else if (type == 2)
        {
            int pos, newVal;
            cin >> pos >> newVal;
            segTree.updateSegmentTree(0, 0, n - 1, pos, newVal);
            arr[pos] = newVal;
        }
    }

    return 0;
}