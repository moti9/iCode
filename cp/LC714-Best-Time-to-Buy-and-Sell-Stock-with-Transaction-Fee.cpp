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
        vector<int> noHolding(n, 0), holding(n, 0);
        holding[0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            holding[i] = max(holding[i - 1], noHolding[i - 1] - prices[i]);
            noHolding[i] = max(noHolding[i - 1], holding[i - 1] + prices[i] - fee);
        }
        return noHolding[n - 1] >= 0 ? noHolding[n - 1] : 0;
    }
};

/*
class Solution
{
    int check(int left, int right, vector<int> &prices, int fee)
    {
        int profit = 0;
        for (int i = left + 1; i <= right; i++)
        {
            profit = max(profit, prices[i] - prices[left] - fee);
        }
        return profit;
    }

    int findProfit(int left, int right, vector<int> &prices, int fee)
    {
        if (left < 0 || right < 0 || left >= right)
        {
            return 0;
        }
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }
        int profit = check(left, right, prices, fee);
        if (profit > 0)
        {
            profit += findProfit(left - 2, left - 1, prices, fee);
        }
        profit = max(profit, findProfit(left - 1, right, prices, fee));
        profit = (profit < 0) ? 0 : profit;
        return dp[left][right] = profit;
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n <= 1)
        {
            return 0;
        }
        return findProfit(n - 2, n - 1, prices, fee);
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