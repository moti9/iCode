#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findProfit(int ind, int buy, int fee, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == prices.size())
        {
            return 0;
        }

        if (dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }

        int profit = 0;
        if (buy == 1)
        {
            profit = max(-prices[ind] + findProfit(ind + 1, 0, fee, prices, dp), findProfit(ind + 1, 1, fee, prices, dp));
        }
        else
        {
            profit = max(prices[ind] - fee + findProfit(ind + 1, 1, fee, prices, dp), findProfit(ind + 1, 0, fee, prices, dp));
        }
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findProfit(0, 1, fee, prices, dp);
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

    int fee;
    cin >> fee;

    Solution sol;
    cout << sol.maxProfit(prices, fee) << endl;

    return 0;
}