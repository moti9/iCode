#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N)
// SC- O(N)

class Solution
{
public:
    int cutRod(vector<int> &price, int n)
    {
        vector<int> dp(n + 1);

        for (int len = 0; len <= n; len++)
        {
            dp[len] = len * price[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int len = 0; len <= n; len++)
            {
                int notCut = dp[len];
                int cut = 0;
                if (ind + 1 <= len)
                {
                    cut = price[ind] + dp[len - ind - 1];
                }
                dp[len] = max(cut, notCut);
            }
        }
        return dp[n];
    }
};

// TC- O(N*N)
// SC- O(N + N)
/*
class Solution
{
public:
    int cutRod(vector<int> &price, int n)
    {
        vector<int> dp(n + 1);

        for (int len = 0; len <= n; len++)
        {
            dp[len] = len * price[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            vector<int> curr(n + 1);
            for (int len = 0; len <= n; len++)
            {
                int notCut = dp[len];
                int cut = 0;
                if (ind + 1 <= len)
                {
                    cut = price[ind] + curr[len - ind - 1];
                }
                curr[len] = max(cut, notCut);
            }
            dp = curr;
        }
        return dp[n];
    }
};
*/

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