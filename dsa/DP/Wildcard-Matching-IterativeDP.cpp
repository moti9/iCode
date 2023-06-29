#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool isMatch(string str, string pattern)
    {
        int n = pattern.length();
        int m = str.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[0][0] = 1;
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            int flag = 1;
            for (int ii = 1; ii <= i; ii++)
            {
                if (pattern[ii - 1] != '*')
                {
                    flag = 0;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pattern[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    string str, pattern;
    cin >> str;
    cin >> pattern;

    Solution sol;
    cout << sol.isMatch(str, pattern) << endl;

    return 0;
}