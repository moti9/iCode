#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int longestCommon(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp)
    {
        if (ind1 <= 0 || ind2 <= 0)
        {
            return 0;
        }
        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }
        if (str1[ind1 - 1] == str2[ind2 - 1])
        {
            return dp[ind1][ind2] = 1 + longestCommon(ind1 - 1, ind2 - 1, str1, str2, dp);
        }
        else
        {
            return dp[ind1][ind2] = 0 + max(longestCommon(ind1 - 1, ind2, str1, str2, dp), longestCommon(ind1, ind2 - 1, str1, str2, dp));
        }
    }

public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int lcs = longestCommon(n, m, str1, str2, dp);

        int i = n, j = m;
        string ans = "";
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans = str1[i - 1] + ans;
                i -= 1;
                j -= 1;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans = str1[i - 1] + ans;
                i -= 1;
            }
            else
            {
                ans = str2[j - 1] + ans;
                j -= 1;
            }
        }
        while (i > 0)
        {
            ans = str1[i - 1] + ans;
            i -= 1;
        }

        while (j > 0)
        {
            ans = str2[j - 1] + ans;
            j -= 1;
        }

        return ans;
    }
};

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    Solution sol;
    cout << sol.shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}