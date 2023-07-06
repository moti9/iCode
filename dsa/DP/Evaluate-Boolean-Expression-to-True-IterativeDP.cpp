#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int evaluateExp(string &exp)
    {
        int n = exp.length();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > j)
                {
                    continue;
                }

                for (int isTrue = 0; isTrue <= 1; isTrue++)
                {

                    if (i == j)
                    {
                        if (isTrue == 1)
                        {
                            dp[i][j][isTrue] = exp[i] == 'T';
                        }
                        else
                        {
                            dp[i][j][isTrue] = exp[i] == 'F';
                        }
                        continue;
                    }

                    long long ways = 0;

                    for (int ind = i + 1; ind < j; ind += 2)
                    {
                        long long lT = dp[i][ind - 1][1];
                        long long lF = dp[i][ind - 1][0];
                        long long rT = dp[ind + 1][j][1];
                        long long rF = dp[ind + 1][j][0];

                        if (exp[ind] == '&')
                        {
                            // T & T = T, T & F = F, F & T = F, F & F = F
                            if (isTrue == 1)
                            {
                                ways = (ways + (lT * rT) % mod) % mod;
                            }
                            else
                            {
                                ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
                            }
                        }
                        else if (exp[ind] == '|')
                        {
                            // T | T = T, T | F = T, F | T = T, F | F = F
                            if (isTrue == 1)
                            {
                                ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
                            }
                            else
                            {
                                ways = (ways + (lF * rF) % mod) % mod;
                            }
                        }
                        else
                        {
                            // T ^ T = F, T ^ F = T, F ^ T = T, F ^ F = F
                            if (isTrue == 1)
                            {
                                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                            }
                            else
                            {
                                ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
                            }
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }
        return dp[0][n - 1][1];
    }
};

int main()
{
    string exp;
    cin >> exp;

    Solution sol;
    cout << sol.evaluateExp(exp) << endl;

    return 0;
}