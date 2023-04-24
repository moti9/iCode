#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int minSumPath(int row, int col, vector<vector<int>> grid)
{
    if (row == 0 && col == 0)
    {
        return grid[row][col];
    }
    if (row < 0 || col < 0)
    {
        return 1e9;
    }
    int up = grid[row][col] + minSumPath(row - 1, col, grid);
    int left = grid[row][col] + minSumPath(row, col - 1, grid);
    return min(up, left);
}

// Memoization
int minSumPath(int row, int col, vector<vector<int>> grid, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return grid[row][col];
    }
    if (row < 0 || col < 0)
    {
        return 1e9;
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    int up = grid[row][col] + minSumPath(row - 1, col, grid, dp);
    int left = grid[row][col] + minSumPath(row, col - 1, grid, dp);
    return dp[row][col] = min(up, left);
}

// Tabulation
int minSumPaths(int row, int col, vector<vector<int>> grid)
{
    vector<vector<int>> dp(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                int up = INT_MAX, left = INT_MAX;
                if (i > 0)
                    up = grid[i][j] + dp[i - 1][j];
                if (j > 0)
                    left = grid[i][j] + dp[i][j - 1];
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[row - 1][col - 1];
}

// Space Optimization
int minSumPathSP(int row, int col, vector<vector<int>> grid)
{
    vector<int> dp(col, 0);
    // dp[0] = grid[0][0];
    for (int i = 0; i < row; i++)
    {
        vector<int> temp(col, 0);
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
            {
                temp[j] = grid[i][j];
            }
            else
            {
                int up = INT_MAX, left = INT_MAX;
                if (i > 0)
                    up = grid[i][j] + dp[j];
                if (j > 0)
                    left = grid[i][j] + temp[j - 1];
                temp[j] = min(up, left);
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
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Recursive
    cout << minSumPath(n - 1, m - 1, grid) << endl;

    // Memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << minSumPath(n - 1, m - 1, grid, dp) << endl;

    // Tabulation
    cout << minSumPaths(n, m, grid) << endl;

    // Space Optimization
    cout << minSumPathSP(n, m, grid) << endl;
    return 0;
}