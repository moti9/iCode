#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*K)
// SC- O(K + K)

class Solution
{
public:
    int findWays(vector<int> &nums, int tar)
    {
        int n = nums.size();
        vector<int> dp(tar + 1, 0);

        dp[0] = 1;
        if (nums[0] <= tar)
        {
            dp[nums[0]] = 1;
        }
        for (int ind = 1; ind < n; ind++)
        {
            vector<int> curr(tar + 1, 0);
            curr[0] = 1;
            for (int target = 0; target <= tar; target++)
            {
                int notTake = dp[target];
                int take = 0;
                if (nums[ind] <= target)
                {
                    take = dp[target - nums[ind]];
                }
                curr[target] = take + notTake;
            }
            dp = curr;
        }
        return dp[tar];
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