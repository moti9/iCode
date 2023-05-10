#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(1)
// Without using space
class Solution
{
public:
    void merge(vector<int> &nums1, int n, vector<int> &nums2, int m)
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            if (nums1[i] > nums2[0])
            {
                swap(nums1[i], nums2[0]);
            }
            int first = nums2[0];
            for (j = 1; j < m && nums2[j] < first; j++)
            {
                nums2[j - 1] = nums2[j];
            }
            nums2[j - 1] = first;
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