#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1), curr(n + 1);
        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= n; ind2++)
            {
                if (s[ind1 - 1] == s[n - ind2])
                {
                    curr[ind2] = 1 + dp[ind2 - 1];
                }
                else
                {
                    curr[ind2] = max(dp[ind2], curr[ind2 - 1]);
                }
            }
            dp = curr;
        }
        return n - dp[n];
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minInsertions(s) << endl;

    return 0;
}