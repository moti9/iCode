#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findProfit(int ind, int transaction, vector<int> &prices)
    {
        if (ind == prices.size() || transaction == 4)
        {
            return 0;
        }

        if (transaction % 2 == 0)
        {
            return max(-prices[ind] + findProfit(ind + 1, transaction + 1, prices), findProfit(ind + 1, transaction, prices));
        }
        else
        {
            return max(prices[ind] + findProfit(ind + 1, transaction + 1, prices), findProfit(ind + 1, transaction, prices));
        }
    }

public:
    int maxProfit(vector<int> &prices)
    {
        return findProfit(0, 0, prices);
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