#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int ind = 0; ind < n; ind++)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                dp[ind][buy][0] = 0;
            }
        }
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
                {
                    int profit = 0;
                    if (buy == 1)
                    {
                        profit = max(-prices[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind] + dp[ind + 1][1][cap - 1], 0 + dp[ind + 1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][k];
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    int k;
    cin >> k;

    Solution sol;
    cout << sol.maxProfit(k, prices) << endl;

    return 0;
}