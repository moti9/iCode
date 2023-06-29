#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool isAllStars(string &str, int ind)
    {
        for (int i = 1; i <= ind; i++)
        {
            if (str[i - 1] != '*')
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isMatch(string str, string pattern)
    {
        int n = pattern.length();
        int m = str.length();
        vector<bool> dp(m + 1, false), curr(m + 1, false);

        dp[0] = true;

        // for (int j = 1; j <= m; j++)
        // {
        //     dp[j] = 0;
        // }

        for (int i = 1; i <= n; i++)
        {
            curr[0] = isAllStars(pattern, i);
            for (int j = 1; j <= m; j++)
            {
                if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
                {
                    curr[j] = dp[j - 1];
                }
                else if (pattern[i - 1] == '*')
                {
                    curr[j] = dp[j] | curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            dp = curr;
        }
        return dp[m];
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