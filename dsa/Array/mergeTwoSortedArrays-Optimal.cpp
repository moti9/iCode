#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N+M)
// SC- O(1)
// Using gap method-gap=(N+M)/2
class Solution
{
public:
    void merge(vector<int> &nums1, int n, vector<int> &nums2, int m)
    {
        int gap = ceil((float)(n + m) / 2);
        while (gap > 0)
        {
            int i = 0;
            int j = gap;
            while (j < (n + m))
            {
                if (j < n && nums1[i] > nums1[j])
                {
                    swap(nums1[i], nums1[j]);
                }
                else if (j >= n && i < n && nums1[i] > nums2[j - n])
                {
                    swap(nums1[i], nums2[j - n]);
                }
                else if (j >= n && i >= n && nums2[i - n] > nums2[j - n])
                {
                    swap(nums2[i - n], nums2[j - n]);
                }
                i += 1;
                j += 1;
            }

            if (gap == 1)
            {
                gap = 0;
            }
            else
            {
                gap = ceil((float)gap / 2);
            }
        }
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
    Solution sol;
    sol.merge(arr1, n, arr2, m);
    for (auto a : arr1)
        cout << a << " ";
    cout << "\n";
    for (auto a : arr2)
        cout << a << " ";
    cout << "\n";

    return 0;
}