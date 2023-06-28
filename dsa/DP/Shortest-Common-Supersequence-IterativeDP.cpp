#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (str1[ind1 - 1] == str2[ind2 - 1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else
                {
                    dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }

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