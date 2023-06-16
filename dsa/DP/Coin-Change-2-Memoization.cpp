#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*V)
// SC- O(N + N*V)

class Solution
{
    long countWays(int ind, int target, vector<int> &arr, vector<vector<long>> &dp)
    {
        if (ind == 0)
        {
            if (target % arr[0] == 0)
            {
                return 1;
            }
            return 0;
        }
        if (dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        long notTake = countWays(ind - 1, target, arr, dp);
        long take = 0;
        if (arr[ind] <= target)
        {
            take = countWays(ind, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = (take + notTake);
    }

public:
    long countWaysToMakeChange(vector<int> &arr, int n, int value)
    {
        vector<vector<long>> dp(n, vector<long>(value + 1, -1));
        return countWays(n - 1, value, arr, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int value;
    cin >> value;

    Solution sol;
    cout << sol.countWaysToMakeChange(arr, n, value) << endl;

    return 0;
}