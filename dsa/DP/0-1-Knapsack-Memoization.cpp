#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*W)
// SC- O(N + N*W)

class Solution
{
    int maxSteal(int ind, int wt, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (weight[ind] <= wt)
            {
                return value[0];
            }
            return 0;
        }
        if (dp[ind][wt] != -1)
        {
            return dp[ind][wt];
        }
        int notTake = maxSteal(ind - 1, wt, weight, value, dp);
        int take = 0;
        if (weight[ind] <= wt)
        {
            take = value[ind] + maxSteal(ind - 1, wt - weight[ind], weight, value, dp);
        }
        return dp[ind][wt] = max(take, notTake);
    }

public:
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
        return maxSteal(n - 1, maxWeight, weight, value, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> value(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    int maxWeight;
    cin >> maxWeight;

    Solution sol;
    cout << sol.knapsack(weight, value, n, maxWeight) << endl;

    return 0;
}