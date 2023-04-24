#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int solve(int ind, int k, vector<int> nums)
{
    if (k == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        if (nums[ind] == k)
        {
            return 1;
        }
        return 0;
    }
    int notPick = solve(ind - 1, k, nums);
    int pick = 0;
    if (nums[ind] <= k)
    {
        pick = solve(ind - 1, k - nums[ind], nums);
    }
    return pick + notPick;
}

// Memoization
int solve(int ind, int k, vector<int> nums, vector<vector<int>> &dp)
{
    if (k == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        return nums[0] == k;
    }
    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }
    int notPick = solve(ind - 1, k, nums);
    int pick = 0;
    if (nums[ind] <= k)
    {
        pick = solve(ind - 1, k - nums[ind], nums);
    }
    return dp[ind][k] = pick + notPick;
}

// Tabulation
int solve(int n, int tar, vector<int> nums)
{
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (nums[0] <= tar)
    {
        dp[0][nums[0]] = 1;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int k = 1; k <= tar; k++)
        {
            int notPick = dp[ind - 1][k];
            int pick = 0;
            if (nums[ind] <= k)
            {
                pick = dp[ind - 1][k - nums[ind]];
            }
            return dp[ind][k] = pick + notPick;
        }
    }
    return dp[n - 1][tar];
}

// Space Optimization
int solve(int n, int tar, vector<int> nums)
{
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
    prev[0] = curr[0] = 1;
    if (nums[0] <= tar)
    {
        prev[nums[0]] = 1;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int k = 1; k <= tar; k++)
        {
            int notPick = prev[k];
            int pick = 0;
            if (nums[ind] <= k)
            {
                pick = prev[k - nums[ind]];
            }
            return curr[k] = pick + notPick;
        }
        prev = curr;
    }
    return curr[tar];
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    // return solve()
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

    cout << findWays(nums, k) << endl;

    return 0;
}