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
    int mid = (low + high) >> 1;
    int left = query(2 * ind + 1, low, mid, l, r, segment);
    int right = query(2 * ind + 2, mid + 1, high, l, r, segment);
    return min(left, right);
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
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r, segment) << endl;
    }

    return 0;
}