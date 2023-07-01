#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);

            dp[ind][0] = max(prices[ind] - fee + dp[ind + 1][1], dp[ind + 1][0]);
        }

        return dp[0][1];
    }
};

/*
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy == 1)
                {
                    profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                }
                else
                {
                    profit = max(prices[ind] - fee + dp[ind + 1][1], dp[ind + 1][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];
    }
};
*/

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    int fee;
    cin >> fee;

    Solution sol;
    cout << sol.maxProfit(prices, fee) << endl;

    return 0;
}