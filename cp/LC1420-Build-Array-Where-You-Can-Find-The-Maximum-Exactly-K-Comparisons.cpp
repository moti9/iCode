#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
    const int mod = 1e9 + 7;
    int solve(int i, int j, int k, int n, int m, int s, vector<vector<vector<int>>> &dp)
    {
        if (i == n)
        {
            return k == 0;
        }
        if (k < 0)
            return 0;

        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }
        int ans = 0;
        for (int num = 1; num <= j; num++)
        {
            ans = (ans + solve(i + 1, j, k, n, m, s, dp)) % mod;
        }
        for (int num = j + 1; num <= m; num++)
        {
            ans = (ans + solve(i + 1, num, k - 1, n, m, s, dp)) % mod;
        }
        return dp[i][j][k] = ans;
    }

public:
    int numOfArrays(int n, int m, int k)
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return solve(0, 0, k, n, m, k, dp);
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    Solution sol;
    cout << sol.numOfArrays(n, m, k) << endl;

    return 0;
}