#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*W)
// SC- O(W)

class Solution
{
public:
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        vector<int> dp(maxWeight + 1);
        for (int wt = weight[0]; wt <= maxWeight; wt++)
        {
            dp[wt] = value[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int wt = maxWeight; wt >= 0; wt--)
            {
                int notTake = dp[wt];
                int take = 0;
                if (weight[ind] <= wt)
                {
                    take = value[ind] + dp[wt - weight[ind]];
                }
                dp[wt] = max(take, notTake);
            }
        }
        return dp[maxWeight];
    }
};

// TC- O(N*W)
// SC- O(W + W)
/*
class Solution
{
public:
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        vector<int> dp(maxWeight + 1);
        for (int wt = weight[0]; wt <= maxWeight; wt++)
        {
            dp[wt] = value[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            vector<int> curr(maxWeight + 1);
            for (int wt = 0; wt <= maxWeight; wt++)
            {
                int notTake = dp[wt];
                int take = 0;
                if (weight[ind] <= wt)
                {
                    take = value[ind] + dp[wt - weight[ind]];
                }
                curr[wt] = max(take, notTake);
            }
            dp = curr;
        }
        return dp[maxWeight];
    }
};
*/

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