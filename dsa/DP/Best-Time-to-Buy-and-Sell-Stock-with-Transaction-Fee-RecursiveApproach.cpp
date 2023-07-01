#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findProfit(int ind, int buy, int fee, vector<int> &prices)
    {
        if (ind == prices.size())
        {
            return 0;
        }

        int profit = 0;
        if (buy == 1)
        {
            profit = max(-prices[ind] + findProfit(ind + 1, 0, fee, prices), findProfit(ind + 1, 1, fee, prices));
        }
        else
        {
            profit = max(prices[ind] - fee + findProfit(ind + 1, 1, fee, prices), findProfit(ind + 1, 0, fee, prices));
        }
        return profit;
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        return findProfit(0, 1, fee, prices);
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