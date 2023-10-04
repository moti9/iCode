#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void build(int ind, int low, int high, vector<int> &arr1, vector<int> &segment)
{
    if (low == high)
    {
        segment[ind] = arr1[low];
        return;
    }

    int mid = (low + high) >> 1;
    build(2 * ind + 1, low, mid, arr1, segment);
    build(2 * ind + 2, mid + 1, high, arr1, segment);

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
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    vector<int> segment1(4 * n);
    build(0, 0, n - 1, arr1, segment1);
    
    vector<int> segment2(4 * m);
    build(0, 0, m - 1, arr2, segment2);

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
            int minArr1 = query(0, 0, n - 1, l1, r1, segment1);
            int minArr2 = query(0, 0, m - 1, l2, r2, segment2);
            cout << min(minArr1, minArr2) << endl;
        }
        else
        {
            int arrNo, i, val;
            cin >> arrNo >> i >> val;
            if (arrNo == 1)
            {
                update(0, 0, n - 1, i, val, segment1);
                arr1[i] = val;
            }
            else
            {
                update(0, 0, m - 1, i, val, segment2);
                arr2[i] = val;
            }
        }
    }

    return 0;
}