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
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        
        for (int i = 0; i < n; i++)
        {
            dp[i][4] = 0;
        }

        dp[n][4] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int transaction = 3; transaction >= 0; transaction--)
            {
                if (transaction % 2 == 0)
                {
                    dp[ind][transaction] = max(-prices[ind] + dp[ind + 1][transaction + 1], dp[ind + 1][transaction]);
                }
                else
                {
                    dp[ind][transaction] = max(prices[ind] + dp[ind + 1][transaction + 1], dp[ind + 1][transaction]);
                }
            }
        }

        return dp[0][0];
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
    return 0;
}