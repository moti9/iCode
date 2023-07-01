#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findProfit(int ind, int buy, int cap, vector<int> &prices)
    {
        if (cap == 0)
        {
            return 0;
        }
        if (ind == prices.size())
        {
            return 0;
        }

        int profit = 0;
        if (buy == 1)
        {
            profit = max(-prices[ind] + findProfit(ind + 1, 0, cap, prices), 0 + findProfit(ind + 1, 1, cap, prices));
        }
        else
        {
            profit = max(prices[ind] + findProfit(ind + 1, 1, cap - 1, prices), 0 + findProfit(ind + 1, 0, cap, prices));
        }
        return profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return findProfit(0, 1, 2, prices);
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

    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}