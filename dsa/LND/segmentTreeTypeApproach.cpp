#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void build(int ind, int low, int high, vector<int> &arr, vector<int> &segment)
{
    if (low == high)
    {
        segment[ind] = arr[low];
        return;
    }

    int mid = (low + high) >> 1;
    build(2 * ind + 1, low, mid, arr, segment);
    build(2 * ind + 2, mid + 1, high, arr, segment);

    segment[ind] = min(segment[2 * ind + 1], segment[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r, vector<int> &segment)
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
    int left = query(2 * ind + 1, low, mid, l, r, segment);
    int right = query(2 * ind + 2, mid + 1, high, l, r, segment);
    return min(left, right);
}

void update(int ind, int low, int high, int i, int val, vector<int> &segment)
{
    if (low == high)
    {
        segment[ind] = val;
        return;
    }
    int mid = (low + high) >> 1;
    if (i <= mid)
    {
        update(2 * ind + 1, low, mid, i, val, segment);
    }
    else
    {
        update(2 * ind + 2, mid + 1, high, i, val, segment);
    }
    segment[ind] = min(segment[2 * ind + 1], segment[2 * ind + 2]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> segment(4 * n);
    build(0, 0, n - 1, arr, segment);
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
            cout << query(0, 0, n - 1, l, r, segment) << endl;
        }
        else
        {
            int i, val;
            cin >> i >> val;
            update(0, 0, n - 1, i, val, segment);
            arr[i] = val;
        }
    }

    return 0;
}