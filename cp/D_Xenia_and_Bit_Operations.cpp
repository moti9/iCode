#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class SegmentTree
{
public:
    vector<int> segment;
    SegmentTree(int n)
    {
        segment.resize(4 * n);
    }

    void build(int ind, int low, int high, vector<int> &arr, bool flag_or)
    {
        if (low == high)
        {
            segment[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr, !flag_or);
        build(2 * ind + 2, mid + 1, high, arr, !flag_or);
        if (flag_or)
        {
            segment[ind] = segment[2 * ind + 1] | segment[2 * ind + 2];
        }
        else
        {
            segment[ind] = segment[2 * ind + 1] ^ segment[2 * ind + 2];
        }
    }

    void update(int ind, int low, int high, int i, int val, bool flag_or)
    {
        if (low == high)
        {
            segment[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
        {
            update(2 * ind + 1, low, mid, i, val, !flag_or);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, i, val, !flag_or);
        }
        if (flag_or)
        {
            segment[ind] = segment[2 * ind + 1] | segment[2 * ind + 2];
        }
        else
        {
            segment[ind] = segment[2 * ind + 1] ^ segment[2 * ind + 2];
        }
    }
};

class solution
{
public:
    solution()
    {
        int n, m;
        cin >> n >> m;
        int sizes = pow(2, n);
        vector<int> arr(sizes);
        for (int i = 0; i < sizes; i++)
        {
            cin >> arr[i];
        }
        SegmentTree seg(sizes);
        if (n % 2)
        {
            seg.build(0, 0, sizes - 1, arr, true);
        }
        else
        {
            seg.build(0, 0, sizes - 1, arr, false);
        }

        for (int i = 0; i < m; i++)
        {
            int ind, val;
            cin >> ind >> val;
            ind--;
            if (n % 2)
                seg.update(0, 0, sizes - 1, ind, val, true);
            else
                seg.update(0, 0, sizes - 1, ind, val, false);
            cout << seg.segment[0] << "\n";
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

// int query(int ind, int low, int high, int l, int r, bool flag_or)
// {
//     if (r < low || high < l)
//     {
//         return 0;
//     }
//     if (low >= l && high <= r)
//     {
//         return segment[ind];
//     }
//     int mid = (low + high) >> 1;
//     int left = query(2 * ind + 1, low, mid, l, r, !flag_or);
//     int right = query(2 * ind + 2, mid + 1, high, l, r, !flag_or);
//     if (flag_or)
//     {
//         segment[ind] = left | right;
//     }
//     else
//     {
//         segment[ind] = left ^ right;
//     }
//     return segment[ind];
// }