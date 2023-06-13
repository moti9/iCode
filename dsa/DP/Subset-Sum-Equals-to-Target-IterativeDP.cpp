#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*K)
// SC- O(N*K)

class Solution
{
public:
    bool subsetSumToK(int n, int k, vector<int> &nums)
    {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (nums[0] <= k)
        {
            dp[0][nums[0]] = true;
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool take = false, notTake;
                if (nums[ind] <= target)
                {
                    int tar = target - nums[ind];
                    take = dp[ind - 1][tar];
                }
                notTake = dp[ind - 1][target];

                dp[ind][target] = take || notTake;
            }
        }
        return dp[n - 1][k];
    }
};

int main()
{

    return 0;
}