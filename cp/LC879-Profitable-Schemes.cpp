#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define mod 1000000007

class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int mod = 1e9 + 7;
        int len = group.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        dp[0][0] = 1;
        for (int i = 0; i < len; i++)
        {
            int g = group[i];
            int p = profit[i];
            for (int j = n; j >= g; j--)
            {
                for (int k = minProfit; k >= 0; k--)
                {
                    int prevProfit = max(k - p, 0);
                    dp[j][k] = (dp[j][k] + dp[j - g][prevProfit]) % mod;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            ans = (ans + dp[i][minProfit]) % mod;
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    int minProfit;
    cin >> minProfit;
    int m;
    cin >> m;
    vector<int> group(n), price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> group[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    Solution sol;
    cout << sol.profitableSchemes(n, minProfit, group, price) << endl;

    return 0;
}