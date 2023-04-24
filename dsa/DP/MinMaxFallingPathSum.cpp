#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int getMaxPathSum(int row, int col, vector<vector<int>> mat)
{
    if (col < 0 || col >= mat[0].size())
    {
        return -1e7;
    }
    if (row == 0)
    {
        return mat[row][col];
    }
    int up = mat[row][col] + getMaxPathSum(row - 1, col, mat);
    int leftDiag = mat[row][col] + getMaxPathSum(row - 1, col - 1, mat);
    int rightDiag = mat[row][col] + getMaxPathSum(row - 1, col + 1, mat);

    return max(up, max(leftDiag, rightDiag));
}

// Memoization
int getMaxPathSum(int row, int col, vector<vector<int>> mat, vector<vector<int>> &dp)
{
    if (col < 0 || col >= mat[0].size())
    {
        return -1e7;
    }
    if (row == 0)
    {
        return mat[row][col];
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    int up = mat[row][col] + getMaxPathSum(row - 1, col, mat, dp);
    int leftDiag = mat[row][col] + getMaxPathSum(row - 1, col - 1, mat, dp);
    int rightDiag = mat[row][col] + getMaxPathSum(row - 1, col + 1, mat, dp);

    return dp[row][col] = max(up, max(leftDiag, rightDiag));
}

// Tabulation
int findMaxPathSum(int n, int m, vector<vector<int>> mat)
{
    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < m; i++)
    {
        dp[0][i] = mat[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = -1e7, leftDiag = -1e7, rightDiag = -1e7;
            up = mat[i][j] + dp[i - 1][j];
            if (j - 1 >= 0)
                leftDiag = mat[i][j] + dp[i - 1][j - 1];
            if (j + 1 < m)
                rightDiag = mat[i][j] + dp[i - 1][j + 1];

            dp[i][j] = max(up, max(leftDiag, rightDiag));
        }
    }

    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}

// Space Optimization
int maxPathSum(int n, int m, vector<vector<int>> mat)
{
    vector<int> dp(m);
    for (int i = 0; i < m; i++)
    {
        dp[i] = mat[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> temp(m);
        for (int j = 0; j < m; j++)
        {
            int up = -1e7, leftDiag = -1e7, rightDiag = -1e7;
            up = mat[i][j] + dp[j];
            if (j - 1 >= 0)
                leftDiag = mat[i][j] + dp[j - 1];
            if (j + 1 < m)
                rightDiag = mat[i][j] + dp[j + 1];
            temp[j] = max(up, max(leftDiag, rightDiag));
        }
        dp = temp;
    }

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Recursive
    int maxi = -1e7;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, getMaxPathSum(n - 1, i, matrix));
    }
    cout << maxi << endl;

    // Memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));
    maxi = -1e7;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, getMaxPathSum(n - 1, i, matrix, dp));
    }
    cout << maxi << endl;

    // Tabulation
    cout << findMaxPathSum(n, m, matrix) << endl;

    // Space Optimization
    cout << maxPathSum(n, m, matrix) << endl;

    return 0;
}