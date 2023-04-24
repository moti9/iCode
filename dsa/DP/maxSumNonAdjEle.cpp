#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int maxSumNonAdj(int ind, vector<int> nums)
{
    if (ind == 0)
        return nums[0];
    if (ind < 0)
        return 0;
    int left = nums[ind] + maxSumNonAdj(ind - 2, nums);
    int right = maxSumNonAdj(ind - 1, nums);
    return max(left, right);
}

// Memoization
int maxSumNonAdj(int ind, vector<int> nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[0];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int left = nums[ind] + maxSumNonAdj(ind - 2, nums, dp);
    int right = maxSumNonAdj(ind - 1, nums, dp);
    return dp[ind] = max(left, right);
}

// Tabulization
int maxSumNonAdj(vector<int> nums, vector<int> &dp)
{
    int n = nums.size();
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        int curr = max(dp[i - 1], dp[i - 2] + nums[i]);
        dp[i - 1] = max(dp[i - 1], dp[i - 2]);
        dp[i] = curr;
    }
    return dp[n - 1];
}

// SpaceOptimization
int maxSumNonAdj(vector<int> nums)
{
    int prev = nums[0];
    int prev2 = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int curr = max(prev, prev2 + nums[i]);
        prev2 = prev;
        prev = curr;
    }
    return prev;
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

    // Recursive
    cout << maxSumNonAdj(n - 1, nums) << endl;

    // Memoization
    vector<int> dp(n, -1);
    // cout << maxSumNonAdj(n - 1, nums, dp) << endl;

    // Tabulization
    cout << maxSumNonAdj(nums, dp) << endl;

    // Space Optimization
    cout << maxSumNonAdj(nums) << endl;

    return 0;
}