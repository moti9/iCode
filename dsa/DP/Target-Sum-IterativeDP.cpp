#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*S)
// SC- O(N*S)

class Solution
{
public:
    int targetSum(int n, int target, vector<int> &nums)
    {
        int totalSum = 0;
        for (auto num : nums)
        {
            totalSum += num;
        }

        if (totalSum < target)
        {
            return 0;
        }
        if ((totalSum - target) % 2 == 1)
        {
            return 0;
        }

        int newTar = (totalSum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(newTar + 1));

        if (nums[0] == 0)
        {
            dp[0][0] = 2;
        }
        else
        {
            dp[0][0] = 1;
        }
        if (nums[0] != 0 && nums[0] <= newTar)
        {
            dp[0][nums[0]] = 1;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int tar = 0; tar <= newTar; tar++)
            {
                int notTake = dp[ind - 1][tar];
                int take = 0;
                if (nums[ind] <= tar)
                {
                    take = dp[ind - 1][tar - nums[ind]];
                }

                dp[ind][tar] = (take + notTake);
            }
        }
        return dp[n - 1][newTar];
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

    int target;
    cin >> target;

    Solution sol;
    cout << sol.targetSum(n, target, nums);

    return 0;
}