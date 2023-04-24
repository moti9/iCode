#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
bool solved(int ind, int k, vector<int> nums)
{
    if (k == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        return nums[0] == k;
    }
    bool pick = 0, notpick = 0;
    notpick = solved(ind - 1, k, nums);
    if (nums[ind] <= k)
    {
        pick = solved(ind - 1, k - nums[ind], nums);
    }
    return pick | notpick;
}

// Memoization

bool solve(int ind, int k, vector<int> nums, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        return nums[0] == k;
    }
    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }
    bool notpick = solve(ind - 1, k, nums, dp);
    bool pick = false;
    if (nums[ind] <= k)
    {
        pick = solve(ind - 1, k - nums[ind], nums, dp);
    }
    return dp[ind][k] = pick | notpick;
}

// Tabulation

bool solve2(int n, int k, vector<int> nums)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (nums[0] <= k)
        dp[0][nums[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notPick = dp[ind - 1][target];
            bool pick = false;
            if (nums[ind] <= target)
            {
                pick = dp[ind - 1][target - nums[ind]];
            }
            dp[ind][target] = pick | notPick;
        }
    }
    return dp[n - 1][k];
}

// Space Optimization
bool solve(int n, int k, vector<int> nums)
{
    vector<bool> prev(k + 1, false), curr(k + 1, 0);
    if (nums[0] <= k)
        prev[nums[0]] = true;
    prev[0] = curr[0] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notPick = prev[target];
            bool pick = false;
            if (nums[ind] <= target)
            {
                pick = prev[target - nums[ind]];
            }
            curr[target] = pick | notPick;
        }
        prev = curr;
    }
    return prev[k];
}

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    return solve(n, k, nums);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    cout << subarraySum(nums, k) << endl;

    return 0;
}