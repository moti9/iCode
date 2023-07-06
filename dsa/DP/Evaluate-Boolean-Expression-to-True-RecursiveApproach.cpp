#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    long long countWays(int i, int j, int isTrue, string &exp)
    {
        if (i > j)
        {
            return 0;
        }

        if (i == j)
        {
            if (isTrue == 1)
            {
                return exp[i] == 'T';
            }
            else
            {
                return exp[i] == 'F';
            }
        }

        long long ways = 0;

        for (int ind = i + 1; ind < j; ind++)
        {
            long long lT = countWays(i, ind - 1, 1, exp);
            long long lF = countWays(i, ind - 1, 0, exp);
            long long rT = countWays(ind + 1, j, 1, exp);
            long long rF = countWays(ind + 1, j, 0, exp);

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
        return ways;
    }

public:
    int evaluateExp(string &exp)
    {
        int n = exp.length();
        return countWays(0, n - 1, 1, exp);
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