#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N)
// SC- O(1)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            int buy = prices[i];
            for (int j = i + 1; j < prices.size(); j++)
            {
                ans = max(ans, prices[j] - buy);
            }
        }
        return ans;
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