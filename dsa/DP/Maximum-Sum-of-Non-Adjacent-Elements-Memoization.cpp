#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(N+N)

class Solution
{
    int findMaxSum(int ind, vector<int> &nums, vector<int> &dp)
    {
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        if (ind == 0)
            return nums[0];
        int take = nums[ind] + findMaxSum(ind - 2, nums, dp);
        int notTake = findMaxSum(ind - 1, nums, dp);
        return dp[ind] = max(take, notTake);
    }

public:
    int maximumNonAdjacentSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return findMaxSum(n - 1, nums, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.maximumNonAdjacentSum(nums) << endl;

    return 0;
}