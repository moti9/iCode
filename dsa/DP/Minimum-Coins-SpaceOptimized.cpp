#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*E)
// SC- O(E + E)

class Solution
{
public:
    int minimumElements(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<int> dp(x + 1, 0);
        for (int tar = 0; tar <= x; tar++)
        {
            if (tar % nums[0] == 0)
            {
                dp[tar] = tar / nums[0];
            }
            else
            {
                dp[tar] = 1e9;
            }
        }
        for (int ind = 1; ind < n; ind++)
        {
            vector<int> curr(x + 1, 0);
            for (int tar = 0; tar <= x; tar++)
            {
                int notTake = dp[tar];
                int take = 1e9;
                if (nums[ind] <= tar)
                {
                    take = 1 + curr[tar - nums[ind]];
                }
                curr[tar] = min(take, notTake);
            }
            dp = curr;
        }
        return dp[x] >= 1e9 ? -1 : dp[x];
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