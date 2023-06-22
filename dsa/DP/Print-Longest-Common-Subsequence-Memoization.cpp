#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(N*M + N+M)

class Solution
{
    int lcs(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }

        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }

        if (text1[ind1] == text2[ind2])
        {
            return dp[ind1][ind2] = 1 + lcs(ind1 - 1, ind2 - 1, text1, text2, dp);
        }
        else
        {
            return dp[ind1][ind2] = max(lcs(ind1 - 1, ind2, text1, text2, dp), lcs(ind1, ind2 - 1, text1, text2, dp));
        }
    }

public:
    string longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        int len = lcs(n1 - 1, n2 - 1, text1, text2, dp);

        string ans = "";
        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 && j >= 0)
        {
            if (text1[i] == text2[j])
            {
                ans = text1[i] + ans;
                i -= 1;
                j -= 1;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i -= 1;
            }
            else
            {
                j -= 1;
            }
        }
        return ans;
    }
};

int main()
{
    string text1, text2;
    cin >> text1 >> text2;

    Solution sol;
    cout << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}