#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*S)
// SC- O(N*S + S)

class Solution
{
    int countWays(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target == 0 && nums[0] == 0)
            {
                return 2;
            }
            if (target == 0 || target == nums[0])
            {
                return 1;
            }
            return 0;
        }
        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        int notTake = countWays(ind - 1, target, nums, dp);
        int take = 0;
        if (nums[ind] <= target)
        {
            take = countWays(ind - 1, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = take + notTake;
    }

public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totalSum = 0;
        for (auto a : arr)
        {
            totalSum += a;
        }

        if (totalSum < d)
        {
            return 0;
        }
        if ((totalSum - d) % 2 == 1)
        {
            return 0;
        }
        int tar = (totalSum - d) / 2;
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return countWays(n - 1, tar, arr, dp);
    }
};

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.countPartitions(n, d, arr) << endl;

    return 0;
}