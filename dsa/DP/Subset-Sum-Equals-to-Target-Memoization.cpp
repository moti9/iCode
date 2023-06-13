#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*K)
// SC- O(N+N*K)

class Solution
{
    bool getSubset(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return true;
        }
        if (ind == 0)
        {
            return target == nums[0];
        }
        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        bool take = false, notTake;
        if (nums[ind] <= target)
        {
            target -= nums[ind];
            take = getSubset(ind - 1, target, nums, dp);
            target += nums[ind];
        }
        notTake = getSubset(ind - 1, target, nums, dp);

        return dp[ind][target] = take || notTake;
    }

public:
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return getSubset(n - 1, k, arr, dp);
    }
};

int main()
{

    return 0;
}