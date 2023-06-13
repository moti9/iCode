#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*K)
// SC- O(K+K)

class Solution
{
public:
    bool subsetSumToK(int n, int k, vector<int> &nums)
    {
        vector<bool> dp(k + 1, false);
        dp[0] = true;
        if (nums[0] <= k)
        {
            dp[nums[0]] = true;
        }
        for (int ind = 1; ind < n; ind++)
        {
            vector<bool> curr(k + 1, false);
            curr[0] = true;
            for (int target = 1; target <= k; target++)
            {
                bool take = false, notTake;
                if (nums[ind] <= target)
                {
                    int tar = target - nums[ind];
                    take = dp[tar];
                }
                notTake = dp[target];

                curr[target] = take || notTake;
            }
            dp = curr;
        }
        return dp[k];
    }
};

int main()
{

    return 0;
}