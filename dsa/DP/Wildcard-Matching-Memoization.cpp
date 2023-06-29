#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool checkMatching(int i, int j, string &pattern, string &str, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (i < 0 && j >= 0)
        {
            return false;
        }
        if (j < 0 && i >= 0)
        {
            for (; i >= 0; i--)
            {
                if (pattern[i] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (pattern[i] == str[j] || pattern[i] == '?')
        {
            return dp[i][j] = checkMatching(i - 1, j - 1, pattern, str, dp);
        }
        else if (pattern[i] == '*')
        {
            return dp[i][j] = checkMatching(i - 1, j, pattern, str, dp) | checkMatching(i, j - 1, pattern, str, dp);
        }
        return dp[i][j] = false;
    }

public:
    bool isMatch(string str, string pattern)
    {
        int n = pattern.length();
        int m = str.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return checkMatching(n - 1, m - 1, pattern, str, dp);
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