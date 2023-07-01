#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findProfit(int ind, int transaction, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == prices.size() || transaction == 4)
        {
            return 0;
        }

        if (dp[ind][transaction] != -1)
        {
            return dp[ind][transaction];
        }

        if (transaction % 2 == 0)
        {
            return dp[ind][transaction] = max(-prices[ind] + findProfit(ind + 1, transaction + 1, prices, dp), findProfit(ind + 1, transaction, prices, dp));
        }
        else
        {
            return dp[ind][transaction] = max(prices[ind] + findProfit(ind + 1, transaction + 1, prices, dp), findProfit(ind + 1, transaction, prices, dp));
        }
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return findProfit(0, 0, prices, dp);
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