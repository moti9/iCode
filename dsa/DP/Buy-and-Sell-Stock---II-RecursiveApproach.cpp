#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findProfit(int ind, int buy, vector<int> &prices)
    {
        if (ind == prices.size())
        {
            return 0;
        }

        if (buy == 1)
        {
            return max({-prices[ind] + findProfit(ind + 1, 0, prices), 0 + findProfit(ind + 1, 1, prices)});
        }
        else
        {
            return max({prices[ind] + findProfit(ind + 1, 1, prices), 0 + findProfit(ind + 1, 0, prices)});
        }
    }

public:
    int maxProfit(vector<int> &prices)
    {
        return findProfit(0, 1, prices);
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