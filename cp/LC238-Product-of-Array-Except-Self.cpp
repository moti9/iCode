#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Optimized approach(Space optimize)
// TC- O(N)
// SC- O(N)

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = 1;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            prefix[i] *= suffix;
            suffix *= nums[i];
        }

        return prefix;
    }
};

// Better Approach
// TC- O(N)
// SC- O(N)
/*
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = 1;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        vector<int> ans(n);
        ans[0] = suffix[0];
        ans[n - 1] = prefix[n - 1];
        for (int i = 1; i < n - 1; i++)
        {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};
*/

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution sol;
    vector<int> ans = sol.productExceptSelf(arr);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}