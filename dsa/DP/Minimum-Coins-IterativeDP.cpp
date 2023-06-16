#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*E)
// SC- O(N*E)

class Solution
{
public:
    int minimumElements(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(x + 1, 0));
        for (int tar = 0; tar <= x; tar++)
        {
            if (tar % nums[0] == 0)
            {
                dp[0][tar] = tar / nums[0];
            }
            else
            {
                dp[0][tar] = 1e9;
            }
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int tar = 0; tar <= x; tar++)
            {
                int notTake = dp[ind - 1][tar];
                int take = 1e9;
                if (nums[ind] <= tar)
                {
                    take = 1 + dp[ind][tar - nums[ind]];
                }
                dp[ind][tar] = min(take, notTake);
            }
        }
        return dp[n - 1][x] >= 1e9 ? -1 : dp[n - 1][x];
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
    int x;
    cin >> x;

    Solution sol;
    cout << sol.minimumElements(nums, x);

    return 0;
}