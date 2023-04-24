#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int solve(int left, int right, string &s, vector<vector<int>> &dp)
    {
        if (left > right)
        {
            return 0;
        }
        if (left == right)
        {
            return 1;
        }
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }
        if (s[left] == s[right])
            dp[left][right] = 2 + solve(left + 1, right - 1, s, dp);
        else
            dp[left][right] = max(solve(left + 1, right, s, dp), solve(left, right - 1, s, dp));
        return dp[left][right];
    }

public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> dp(n, vector<int>(n));
        // return solve(0, n - 1, s, dp);
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.longestPalindromeSubseq(s) << endl;

    return 0;
}