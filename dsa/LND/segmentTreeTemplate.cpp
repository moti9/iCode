#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class SegmentTree
{
    vector<int> segment;

public:
    SegmentTree(int n)
    {
        segment.resize(4 * n + 1);
    }
    void build(int ind, int low, int high, vector<int> &arr1)
    {
        if (low == high)
        {
            segment[ind] = arr1[low];
            return;
        }

        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr1);
        build(2 * ind + 2, mid + 1, high, arr1);

        segment[ind] = min(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        // No overlap [l,r, low, high] | [low, high, l, r]
        if (r < low || high < l)
        {
            return INT_MAX;
        }
        // complete overlap
        if (low >= l && high <= r)
        {
            return segment[ind];
        }
        // Partial Overlap
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            segment[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
        {
            update(2 * ind + 1, low, mid, i, val);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, i, val);
        }
        segment[ind] = min(segment[2 * ind + 1], segment[2 * ind + 2]);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    SegmentTree seg1(n);
    seg1.build(0, 0, n - 1, arr1);

    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    SegmentTree seg2(m);
    seg2.build(0, 0, m - 1, arr2);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            int minArr1 = seg1.query(0, 0, n - 1, l1, r1);
            int minArr2 = seg2.query(0, 0, m - 1, l2, r2);
            cout << min(minArr1, minArr2) << endl;
        }
        else
        {
            int arrNo, i, val;
            cin >> arrNo >> i >> val;
            if (arrNo == 1)
            {
                seg1.update(0, 0, n - 1, i, val);
                arr1[i] = val;
            }
            else
            {
                seg2.update(0, 0, m - 1, i, val);
                arr2[i] = val;
            }
        }
    }

    return 0;
}