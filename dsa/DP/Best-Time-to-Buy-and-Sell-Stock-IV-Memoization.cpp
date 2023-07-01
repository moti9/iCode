#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findProfit(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (ind == prices.size() || cap == 0)
        {
            return 0;
        }

        if (dp[ind][buy][cap] != -1)
        {
            return dp[ind][buy][cap];
        }

        int profit = 0;
        if (buy == 1)
        {
            profit = max(-prices[ind] + findProfit(ind + 1, 0, cap, prices, dp), 0 + findProfit(ind + 1, 1, cap, prices, dp));
        }
        else
        {
            profit = max(prices[ind] + findProfit(ind + 1, 1, cap - 1, prices, dp), 0 + findProfit(ind + 1, 0, cap, prices, dp));
        }
        return dp[ind][buy][cap] = profit;
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return findProfit(0, 1, k, prices, dp);
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