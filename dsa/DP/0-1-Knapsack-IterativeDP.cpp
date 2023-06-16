#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*W)
// SC- O(N*W)

class Solution
{
public:
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1));
        for (int wt = weight[0]; wt <= maxWeight; wt++)
        {
            dp[0][wt] = value[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int wt = 0; wt <= maxWeight; wt++)
            {
                int notTake = dp[ind - 1][wt];
                int take = 0;
                if (weight[ind] <= wt)
                {
                    take = value[ind] + dp[ind - 1][wt - weight[ind]];
                }
                dp[ind][wt] = max(take, notTake);
            }
        }
        return dp[n - 1][maxWeight];
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