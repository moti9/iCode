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
        vector<int> dp(5, 0), curr(5, 0);

        dp[4] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int transaction = 3; transaction >= 0; transaction--)
            {
                if (transaction % 2 == 0)
                {
                    curr[transaction] = max(-prices[ind] + dp[transaction + 1], dp[transaction]);
                }
                else
                {
                    curr[transaction] = max(prices[ind] + dp[transaction + 1], dp[transaction]);
                }
            }
            dp = curr;
        }

        return dp[0];
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