#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findProfit(int ind, int transNo, int n, int k, vector<int> &prices)
    {
        if (ind == n || transNo == k)
        {
            return 0;
        }

        int profit = 0;
        if (transNo % 2 == 0)
        {
            profit = max(-prices[ind] + findProfit(ind + 1, transNo + 1, n, k, prices), 0 + findProfit(ind + 1, transNo, n, k, prices));
        }
        else
        {
            profit = max(prices[ind] + findProfit(ind + 1, transNo + 1, n, k, prices), 0 + findProfit(ind + 1, transNo, n, k, prices));
        }
        return profit;
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        return findProfit(0, 0, n, 2 * k, prices);
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