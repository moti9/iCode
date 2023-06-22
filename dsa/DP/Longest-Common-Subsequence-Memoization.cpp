#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(N*M + N+M)

class Solution
{
public:
    int commonSubseq(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
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
            return dp[ind1][ind2] = 1 + commonSubseq(ind1 - 1, ind2 - 1, text1, text2, dp);
        }
        else
        {
            return dp[ind1][ind2] = 0 + max(commonSubseq(ind1 - 1, ind2, text1, text2, dp), commonSubseq(ind1, ind2 - 1, text1, text2, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {

        int n1 = text1.size();
        int n2 = text2.size();

        if (text1 == text2)
        {
            return n1;
        }
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return commonSubseq(n1 - 1, n2 - 1, text1, text2, dp);
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