#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(N*M)

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();

        if (text1 == text2)
        {
            return n1;
        }

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int ind1 = 1; ind1 <= n1; ind1++)
        {
            for (int ind2 = 1; ind2 <= n2; ind2++)
            {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else
                {
                    dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};

/*
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {

        int n1 = text1.size();
        int n2 = text2.size();

        if (text1 == text2)
        {
            return n1;
        }
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= n2; i++)
        {
            dp[0][i] = 0;
        }

        for (int ind1 = 1; ind1 <= n1; ind1++)
        {
            for (int ind2 = 1; ind2 <= n2; ind2++)
            {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else
                {
                    dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }

        return dp[n1][n2];
    }
};
*/

int main()
{
    string text1, text2;
    cin >> text1 >> text2;

    Solution sol;
    cout << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}