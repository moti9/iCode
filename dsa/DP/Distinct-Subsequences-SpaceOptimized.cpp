#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<double> dp(m + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[j] = dp[j - 1] + dp[j];
                }
                // else
                // {
                //     dp[j] = dp[j];
                // }
            }
        }
        return (int)dp[m];
    }
};

/*
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<double> dp(m + 1, 0), curr(m + 1, 0);
        dp[0] = curr[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    curr[j] = dp[j - 1] + dp[j];
                }
                else
                {
                    curr[j] = dp[j];
                }
            }
            dp = curr;
        }
        return (int)dp[m];
    }
};

*/

int main()
{
    string s, t;
    cin >> s >> t;

    Solution sol;
    cout << sol.numDistinct(s, t) << endl;

    return 0;
}