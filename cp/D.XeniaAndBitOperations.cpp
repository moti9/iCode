#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class SegmentTree
{
public:
    vector<int> segTree;
    SegmentTree(int n)
    {
        segTree.resize(4 * n);
    }

    void buildSegmentTree(int index, int left, int right, vector<int> &arr, bool isXOR)
    {
        if (left == right)
        {
            segTree[index] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        buildSegmentTree(2 * index + 1, left, mid, arr, !isXOR);
        buildSegmentTree(2 * index + 2, mid + 1, right, arr, !isXOR);
        segTree[index] = isXOR ? (segTree[2 * index + 1] ^ segTree[2 * index + 2]) : (segTree[2 * index + 1] | segTree[2 * index + 2]);
    }

    void updateSegmentTree(int index, int left, int right, int pos, int newVal, bool isXOR)
    {
        if (left == right)
        {
            segTree[index] = newVal;
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid)
        {
            updateSegmentTree(2 * index + 1, left, mid, pos, newVal, !isXOR);
        }
        else
        {
            updateSegmentTree(2 * index + 2, mid + 1, right, pos, newVal, !isXOR);
        }
        segTree[index] = isXOR ? (segTree[2 * index + 1] ^ segTree[2 * index + 2]) : (segTree[2 * index + 1] | segTree[2 * index + 2]);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int arrSize = 1 << n;
    vector<int> arr(arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }

    bool isXOR = !(n & 1);
    SegmentTree segTree(arrSize);
    segTree.buildSegmentTree(0, 0, arrSize - 1, arr, isXOR);

    for (int i = 0; i < m; i++)
    {
        int p, b;
        cin >> p >> b;
        p--;
        segTree.updateSegmentTree(0, 0, arrSize - 1, p, b, isXOR);
        cout << segTree.segTree[0] << "\n";
    }

    return 0;
}