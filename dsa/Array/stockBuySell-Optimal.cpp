#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(1)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxPro = 0;
        int n = prices.size();
        int minPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }

        return maxPro;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> stock_price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stock_price[i];
    }
    Solution sol;
    cout << sol.maxProfit(stock_price) << endl;

    return 0;
}