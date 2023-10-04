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

    void build(int ind, int low, int high, vector<int> &freq)
    {
        if (low == high)
        {
            segment[ind] = freq[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, freq);
        build(2 * ind + 2, mid + 1, high, freq);
        segment[ind] = segment[2 * ind + 1] + segment[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r)
    {
        if (r < low || high < l)
        {
            return 0;
        }
        if (low >= l && high <= r)
        {
            return segment[ind];
        }
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return (left + right);
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            segment[ind] += val;
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
        segment[ind] = segment[2 * ind + 1] + segment[2 * ind + 2];
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
        int mx = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }
        mx += 1;
        vector<int> freq(mx);
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]++;
        }
        SegmentTree seg(mx);
        seg.build(0, 0, mx - 1, freq);

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            freq[arr[i]]--;
            seg.update(0, 0, mx - 1, arr[i], -1);
            cnt += seg.query(0, 0, mx - 1, 1, arr[i] - 1);
        }
        cout << cnt << "\n";
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
    cin >> ttt;
    while (ttt--)
    {
        solution moti;
    }
    return 0;
}
