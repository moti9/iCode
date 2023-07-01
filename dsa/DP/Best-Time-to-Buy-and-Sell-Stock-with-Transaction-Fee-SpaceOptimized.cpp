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
        vector<int> dp(2, 0), curr(2, 0);

        dp[0] = dp[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            curr[1] = max(-prices[ind] + dp[0], dp[1]);

            curr[0] = max(prices[ind] - fee + dp[1], dp[0]);

            dp = curr;
        }

        return dp[1];
    }
};

/*
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> dp(2, 0), curr(2, 0);

        dp[0] = dp[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy == 1)
                {
                    profit = max(-prices[ind] + dp[0], dp[1]);
                }
                else
                {
                    profit = max(prices[ind] - fee + dp[1], dp[0]);
                }
                curr[buy] = profit;
            }
            dp = curr;
        }

        return dp[1];
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