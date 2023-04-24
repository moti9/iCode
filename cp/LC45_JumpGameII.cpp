#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int solve(int ind, vector<int> &nums, vector<int> &dp)
    {
        if (ind >= nums.size())
        {
            return 1e7;
        }
        if (ind == nums.size() - 1)
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int jump = ind + nums[ind], ans = 1e7;
        for (int i = ind + 1; i < nums.size() && i <= jump; i++)
        {
            ans = min(ans, solve(i, nums, dp));
        }
        return dp[ind] = 1 + ans;
    }

public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // return solve(0, nums, dp);
        int countJump = 0, maxJump = 0, currEnd = 0;
        for (int i = 0; i < n; i++)
        {
            maxJump = max(maxJump, i + nums[i]);
            if (i == currEnd && i != n - 1)
            {
                countJump++;
                currEnd = maxJump;
            }
        }
        return countJump;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i += 1)
    {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.jump(nums) << endl;
    return 0;
}