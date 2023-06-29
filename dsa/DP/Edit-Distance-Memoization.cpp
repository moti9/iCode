#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int countOperations(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
    {
        if (j < 0)
        {
            return i + 1;
        }
        if (i < 0)
        {
            return j + 1;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (str1[i] == str2[j])
        {
            return dp[i][j] = 0 + countOperations(i - 1, j - 1, str1, str2, dp);
        }
        else
        {
            int opr = 1 + countOperations(i, j - 1, str1, str2, dp);
            opr = min(opr, 1 + countOperations(i - 1, j, str1, str2, dp));
            opr = min(opr, 1 + countOperations(i - 1, j - 1, str1, str2, dp));
            return dp[i][j] = opr;
        }
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countOperations(n - 1, m - 1, word1, word2, dp);
    }
};

int main()
{
    string word1, word2;
    cin >> word1 >> word2;

    Solution sol;
    cout << sol.minDistance(word1, word2) << endl;

    return 0;
}