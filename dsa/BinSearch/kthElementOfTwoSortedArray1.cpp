#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int kthElement(vector<int> &arr1, int n1, vector<int> &arr2, int n2, int k)
    {
        if (n1 > n2)
            return kthElement(arr2, n2, arr1, n1, k);
        int n = n1 + n2;
        int low = max(0, k - n2), high = min(k, n1);
        int left = k;
        while (low <= high)
        {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = arr1[mid1];
            if (mid2 < n1)
                r2 = arr2[mid2];
            if (mid1 - 1 >= 0)
                l1 = arr1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = arr2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
                return max(l1, l2);
            else if (l1 > r2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return 0;
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
    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    int k;
    cin >> k;

    Solution sol;
    cout << sol.kthElement(arr1, n, arr2, m, k) << endl;

    return 0;
}