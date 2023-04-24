#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int uniquePaths(int row, int col)
{
    if (row == 0 && col == 0)
    {
        return 1;
    }
    if (row < 0 || col < 0)
    {
        return 0;
    }
    int up = uniquePaths(row - 1, col);
    int left = uniquePaths(row, col - 1);
    return up + left;
}

// Memoization
int uniquePaths(int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return 1;
    }
    if (row < 0 || col < 0)
    {
        return 0;
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    int up = uniquePaths(row - 1, col);
    int left = uniquePaths(row, col - 1);
    return dp[row][col] = up + left;
}

// Tabulation
int uniquePath(int row, int col)
{
    vector<vector<int>> dp(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                int left = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[row - 1][col - 1];
}

// Space Optimization
int uniquePathSP(int row, int col)
{
    vector<int> dp(col, 0);
    dp[0] = 1;
    for (int i = 0; i < row; i++)
    {
        vector<int> temp(col, 0);
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
            }
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[j];
                if (j > 0)
                    left = temp[j - 1];
                temp[j] = up + left;
            }
        }
        dp = temp;
    }
    return dp[col - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;

    // Recursive
    cout << uniquePaths(n - 1, m - 1) << endl;

    // Memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << uniquePaths(n - 1, m - 1, dp) << endl;

    // Tabulation
    cout << uniquePath(n, m) << endl;

    // Space Optimization
    cout << uniquePathSP(n, m) << endl;
    return 0;
}