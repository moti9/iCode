#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*K)
// SC- O(N + N*K)

class Solution
{
    int countWays(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return dp[ind][target] = 1;
        }
        if (ind == 0)
        {
            return dp[ind][target] = target == nums[0];
        }
        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        int notTake = countWays(ind - 1, target, nums, dp);
        int take = 0;
        if (nums[ind] <= target)
        {
            take = countWays(ind - 1, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = take + notTake;
    }

public:
    int findWays(vector<int> &nums, int tar)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return countWays(n - 1, tar, nums, dp);
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

    int tar;
    cin >> tar;

    Solution sol;
    cout << sol.findWays(nums, tar) << endl;

    return 0;
}