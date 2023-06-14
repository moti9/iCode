#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*K)
// SC- O(N*K)

class Solution
{
public:
    int findWays(vector<int> &nums, int tar)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
        for (int ind = 0; ind < n; ind++)
        {
            dp[ind][0] = 1;
        }
        if (nums[0] <= tar)
        {
            dp[0][nums[0]] = 1;
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= tar; target++)
            {
                int notTake = dp[ind - 1][target];
                int take = 0;
                if (nums[ind] <= target)
                {
                    take = dp[ind - 1][target - nums[ind]];
                }
                dp[ind][target] = take + notTake;
            }
        }
        return dp[n - 1][tar];
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