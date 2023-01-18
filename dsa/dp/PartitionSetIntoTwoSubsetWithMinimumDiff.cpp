#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (auto x : arr)
        sum += x;

    int k = sum;

    // vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    // for (int i = 0; i < n; i++)
    // {
    //     dp[i][0] = true;
    // }
    // if (arr[0] <= k)
    //     dp[0][arr[0]] = true;
    // for (int ind = 1; ind < n; ind++)
    // {
    //     for (int target = 1; target <= k; target++)
    //     {
    //         bool notPick = dp[ind - 1][target];
    //         bool pick = false;
    //         if (arr[ind] <= target)
    //         {
    //             pick = dp[ind - 1][target - arr[ind]];
    //         }
    //         dp[ind][target] = pick | notPick;
    //     }
    // }
    // return dp[n - 1][k];

    vector<bool> prev(k + 1, false), curr(k + 1, 0);
    if (arr[0] <= k)
        prev[arr[0]] = true;
    prev[0] = curr[0] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notPick = prev[target];
            bool pick = false;
            if (arr[ind] <= target)
            {
                pick = prev[target - arr[ind]];
            }
            curr[target] = pick | notPick;
        }
        prev = curr;
    }
    // return prev[k];
    int mini = 1e9;
    for (int s1 = 0; s1 <= sum / 2; s1++)
    {
        // if (dp[n - 1][s1])
        if (prev[s1])
        {
            mini = min(mini, abs((sum - s1) - s1));
        }
    }
    return mini;
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
    cout << minSubsetSumDifference(nums, n) << endl;

    return 0;
}