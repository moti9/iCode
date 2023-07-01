#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        int trans = 2 * k;
        vector<int> dp(trans + 1, 0), curr(trans + 1, 0);

        dp[2 * k] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int transNo = trans - 1; transNo >= 0; transNo--)
            {
                int profit = 0;
                if (transNo % 2 == 0)
                {
                    profit = max(-prices[ind] + dp[transNo + 1], 0 + dp[transNo]);
                }
                else
                {
                    profit = max(prices[ind] + dp[transNo + 1], 0 + dp[transNo]);
                }
                curr[transNo] = profit;
            }
            dp = curr;
        }

        return dp[0];
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