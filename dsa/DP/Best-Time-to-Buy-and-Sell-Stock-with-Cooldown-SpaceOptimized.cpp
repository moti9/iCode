#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<int> dp1(2, 0), dp2(2, 0), curr(2, 0);
        dp1[0] = dp1[1] = 0;
        dp2[0] = dp2[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {

            curr[1] = max({-prices[ind] + dp1[0], 0 + dp1[1]});

            curr[0] = max({prices[ind] + dp2[1], 0 + dp1[0]});

            dp2 = dp1;
            dp1 = curr;
        }
        return dp1[1];
    }
};

/*
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        vector<int> dp1(2, 0), dp2(2, 0), curr(2, 0);
        dp1[0] = dp1[1] = 0;
        dp2[0] = dp2[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == 1)
                {
                    curr[buy] = max({-prices[ind] + dp1[0], 0 + dp1[1]});
                }
                else
                {
                    curr[buy] = max({prices[ind] + dp2[1], 0 + dp1[0]});
                }
            }
            dp2 = dp1;
            dp1 = curr;
        }
        return dp1[1];
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

    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}