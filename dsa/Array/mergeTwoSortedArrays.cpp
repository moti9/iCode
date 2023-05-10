#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N+M)+(N+M)log(N+M)+O(N+M)
// SC- O(N+M)
// Brute force- take into a single array->sort->put into original arrays
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> merged;
        for (auto n : nums1)
            merged.push_back(n);
        for (auto n : nums2)
            merged.push_back(n);
        int j = 0;
        for (int i = 0; i < m; i++)
        {
            nums1[i] = merged[j++];
        }
        for (int i = 0; i < n; i++)
        {
            nums2[i] = merged[j++];
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