#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int ind = 0; ind < n; ind++)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                dp[ind][buy][0] = 0;
            }
        }

        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 0; cap <= 2; cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
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

        return dp[0][1][2];
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

    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}