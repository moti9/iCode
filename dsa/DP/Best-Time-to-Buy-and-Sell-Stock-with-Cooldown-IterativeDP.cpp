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

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        dp[n + 1][0] = dp[n + 1][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {

            dp[ind][1] = max({-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]});

            dp[ind][0] = max({prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]});
        }
        return dp[0][1];
    }
};

/*
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        dp[n + 1][0] = dp[n + 1][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == 1)
                {
                    dp[ind][buy] = max({-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]});
                }
                else
                {
                    dp[ind][buy] = max({prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]});
                }
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

    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}