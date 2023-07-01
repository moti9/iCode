#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0), curr(n + 1, 0);

        for (int prevInd = 0; prevInd <= n; prevInd++)
        {
            dp[prevInd] = 0;
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prevInd = ind - 1; prevInd >= -1; prevInd--)
            {
                int notTake = dp[prevInd + 1];
                int take = 0;
                if (prevInd == -1 || nums[ind] > nums[prevInd])
                {
                    take = 1 + dp[ind + 1];
                }
                curr[prevInd + 1] = max(take, notTake);
            }
            dp = curr;
        }
        return dp[0];
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
    cout << sol.lengthOfLIS(nums) << endl;

    return 0;
}