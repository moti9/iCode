#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N)
// SC- O(N*N)

class Solution
{
public:
    int cutRod(vector<int> &price, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1));

        for (int len = 0; len <= n; len++)
        {
            dp[0][len] = len * price[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int len = 0; len <= n; len++)
            {
                int notCut = dp[ind - 1][len];
                int cut = 0;
                if (ind + 1 <= len)
                {
                    cut = price[ind] + dp[ind][len - ind - 1];
                }
                dp[ind][len] = max(cut, notCut);
            }
        }
        return dp[n - 1][n];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    Solution sol;
    cout << sol.cutRod(price, n) << endl;

    return 0;
}