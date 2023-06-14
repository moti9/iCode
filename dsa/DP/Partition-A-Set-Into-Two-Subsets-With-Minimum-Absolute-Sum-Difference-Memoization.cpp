#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*S + N + N)
// SC- O(N*S + N)

class Solution
{
    bool partitionArr(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return dp[ind][target] = true;
        }
        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        if (ind == 0)
        {
            return dp[ind][target] = target == arr[0];
        }
        bool notTake = partitionArr(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
        {
            take = partitionArr(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take || notTake;
    }

public:
    int minSubsetSumDifference(vector<int> &arr, int n)
    {
        int sum = 0;
        for (auto x : arr)
        {
            sum += x;
        }

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        for (int tar = 0; tar <= sum; tar++)
        {
            partitionArr(n - 1, tar, arr, dp);
        }

        int minDiff = 1e9;
        for (int tar = 0; tar <= sum / 2; tar++)
        {
            if (dp[n - 1][tar] == true)
            {
                int diff = abs((sum - tar) - tar);
                minDiff = min(minDiff, diff);
            }
        }
        return minDiff;
    }
};

// TC- O(N*S)
// SC- O(N*S + N)

/*
class Solution
{
    int findMinDiff(int ind, int totalSum, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return dp[ind][sum] = abs((totalSum - sum) - sum);
        }
        if (dp[ind][sum] != -1)
        {
            return dp[ind][sum];
        }
        int notTake = findMinDiff(ind - 1, totalSum, sum, arr, dp);
        int take = findMinDiff(ind - 1, totalSum, sum + arr[ind], arr, dp);
        return dp[ind][sum] = min(take, notTake);
    }

public:
    int minSubsetSumDifference(vector<int> &arr, int n)
    {
        int sum = 0;
        for (auto x : arr)
            sum += x;

        // int k = sum;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return findMinDiff(n - 1, sum, 0, arr, dp);
    }
};
*/

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;

    cout << sol.minSubsetSumDifference(arr, n) << endl;

    return 0;
}