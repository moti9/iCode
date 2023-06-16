#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*W)
// SC- O(N*W)

class Solution
{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        vector<vector<int>> dp(n, vector<int>(w + 1));

        for (int wt = 0; wt <= w; wt++)
        {
            dp[0][wt] = (wt / weight[0]) * profit[0];
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int wt = 0; wt <= w; wt++)
            {
                int notTake = dp[ind - 1][wt];
                int take = 0;
                if (weight[ind] <= wt)
                {
                    take = profit[ind] + dp[ind][wt - weight[ind]];
                }
                dp[ind][wt] = max(take, notTake);
            }
        }

        return dp[n - 1][w];
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