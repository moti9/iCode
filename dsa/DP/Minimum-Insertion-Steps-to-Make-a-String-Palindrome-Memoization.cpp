#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int lcs(int ind1, int ind2, int n, string &s, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }
        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }
        if (s[ind1] == s[n - ind2 - 1])
        {
            return dp[ind1][ind2] = 1 + lcs(ind1 - 1, ind2 - 1, n, s, dp);
        }
        else
        {
            return dp[ind1][ind2] = max(lcs(ind1 - 1, ind2, n, s, dp), lcs(ind1, ind2 - 1, n, s, dp));
        }
    }

public:
    int minInsertions(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return n - lcs(n - 1, n - 1, n, s, dp);
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