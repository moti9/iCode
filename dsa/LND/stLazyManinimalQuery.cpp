#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class SegmentTree
{
    vector<int> segment, lazy;

public:
    SegmentTree(int n)
    {
        segment.resize(4 * n);
        lazy.resize(4 * n);
    }

    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            segment[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        segment[ind] = min(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    void update(int ind, int low, int high, int l, int r, int val)
    {
        if (lazy[ind] != 0)
        {
            segment[ind] += lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (r < low || high < l)
        {
            return;
        }
        if (l <= low && high <= r)
        {
            segment[ind] += val;
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        segment[ind] = min(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        if (lazy[ind] != 0)
        {
            segment[ind] += lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (r < low || high < l)
        {
            return INT_MAX;
        }
        if (l <= low && high <= r)
        {
            return segment[ind];
        }

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }
};

class solution
{
public:
    solution()
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        SegmentTree seg(n);
        seg.build(0, 0, n - 1, arr);

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int l, r;
                cin >> l >> r;
                cout << seg.query(0, 0, n - 1, l, r) << endl;
            }
            else
            {
                int l, r, val;
                cin >> l >> r >> val;
                seg.update(0, 0, n - 1, l, r, val);
            }
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
