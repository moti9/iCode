#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class SegmentTree
{
public:
    vector<int> segTree, lazyTree;
    SegmentTree(int n)
    {
        segTree.resize(4 * n);
        lazyTree.resize(4 * n, 0);
    }

    void buildSegmentTree(int index, int left, int right, vector<int> &arr)
    {
        if (left == right)
        {
            segTree[index] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        buildSegmentTree(2 * index + 1, left, mid, arr);
        buildSegmentTree(2 * index + 2, mid + 1, right, arr);
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    void updateSegmentTree(int index, int left, int right, int l, int r, int val)
    {
        if (lazyTree[index] != 0)
        {
            segTree[index] += (right - left + 1) * lazyTree[index];
            if (left != right)
            {
                lazyTree[2 * index + 1] += lazyTree[index];
                lazyTree[2 * index + 2] += lazyTree[index];
            }
            lazyTree[index] = 0;
        }

        if (right < l || left > r)
            return;

        if (left >= l && right <= r)
        {
            segTree[index] += (right - left + 1) * val;
            if (left != right)
            {
                lazyTree[2 * index + 1] += val;
                lazyTree[2 * index + 2] += val;
            }
            return;
        }

        int mid = (left + right) / 2;
        updateSegmentTree(2 * index + 1, left, mid, l, r, val);
        updateSegmentTree(2 * index + 2, mid + 1, right, l, r, val);
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    int querySegmentTree(int index, int left, int right, int l, int r)
    {
        if (lazyTree[index] != 0)
        {
            segTree[index] += (right - left + 1) * lazyTree[index];
            if (left != right)
            {
                lazyTree[2 * index + 1] += lazyTree[index];
                lazyTree[2 * index + 2] += lazyTree[index];
            }
            lazyTree[index] = 0;
        }

        if (right < l || left > r)
            return 0;

        if (left >= l && right <= r)
            return segTree[index];

        int mid = (left + right) / 2;
        int leftQuery = querySegmentTree(2 * index + 1, left, mid, l, r);
        int rightQuery = querySegmentTree(2 * index + 2, mid + 1, right, l, r);
        return leftQuery + rightQuery;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree segTree(n);
    segTree.buildSegmentTree(0, 0, n - 1, arr);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            int result = segTree.querySegmentTree(0, 0, n - 1, l, r);
            cout << result << "\n";
        } else if (type == 2) {
            int l, r, val;
            cin >> l >> r >> val;
            segTree.updateSegmentTree(0, 0, n - 1, l, r, val);
        }
    }

    

    return 0;
}