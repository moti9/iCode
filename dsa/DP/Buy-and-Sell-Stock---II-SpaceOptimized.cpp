#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int aheadBuy, aheadNotBuy, currBuy, currNotBuy;

        aheadNotBuy = aheadBuy = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            currBuy = max({-prices[ind] + aheadNotBuy, 0 + aheadBuy});

            currNotBuy = max({prices[ind] + aheadBuy, 0 + aheadNotBuy});
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(2, 0), curr(2, 0);

        dp[0] = dp[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            curr[1] = max({-prices[ind] + dp[0], 0 + dp[1]});

            curr[0] = max({prices[ind] + dp[1], 0 + dp[0]});

            dp = curr;
        }
        return dp[1];
    }
};

/*
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(2, 0), curr(2, 0);

        dp[0] = dp[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == 1)
                {
                    curr[buy] = max({-prices[ind] + dp[0], 0 + dp[1]});
                }
                else
                {
                    curr[buy] = max({prices[ind] + dp[1], 0 + dp[0]});
                }
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

    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}