#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*W)
// SC- O(N + N*W)

class Solution
{
    int maxProfit(int ind, int wt, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return (wt / weight[0]) * profit[0];
        }
        if (dp[ind][wt] != -1)
        {
            return dp[ind][wt];
        }
        int notTake = maxProfit(ind - 1, wt, profit, weight, dp);
        int take = 0;
        if (weight[ind] <= wt)
        {
            take = profit[ind] + maxProfit(ind, wt - weight[ind], profit, weight, dp);
        }
        return dp[ind][wt] = max(take, notTake);
    }

public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        return maxProfit(n - 1, w, profit, weight, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> profit(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i] >> weight[i];
    }
    int wt;
    cin >> wt;

    Solution sol;
    cout << sol.unboundedKnapsack(n, wt, profit, weight) << endl;

    return 0;
}