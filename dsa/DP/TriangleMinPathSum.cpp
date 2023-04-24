#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int minPathSum(int row, int col, vector<vector<int>> triangle, int n)
{
    if (row == n - 1)
    {
        return triangle[row][col];
    }
    int down = triangle[row][col] + minPathSum(row + 1, col, triangle, n);
    int diag = triangle[row][col] + minPathSum(row + 1, col + 1, triangle, n);
    return min(down, diag);
}

// Memoization
int minPathSum(int row, int col, vector<vector<int>> triangle, int n, vector<vector<int>> &dp)
{
    if (row == n - 1)
    {
        return triangle[row][col];
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    int down = triangle[row][col] + minPathSum(row + 1, col, triangle, n);
    int diag = triangle[row][col] + minPathSum(row + 1, col + 1, triangle, n);
    return dp[row][col] = min(down, diag);
}

// Tabulation
int minSumPaths(int row, int col, vector<vector<int>> triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diag = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diag);
        }
    }
    return dp[0][0];
}

// Space Optimization
int minSumPath(int row, int col, vector<vector<int>> triangle, int n)
{
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = triangle[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp(n);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[j];
            int diag = triangle[i][j] + dp[j + 1];
            temp[j] = min(down, diag);
        }
        dp = temp;
    }
    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle;
    for (int i = 0; i < n; i++)
    {
        triangle.push_back(vector<int>(i + 1, 0));
        for (int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }

    // Recursive
    cout << minPathSum(0, 0, triangle, n) << endl;

    // Memoization
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << minPathSum(0, 0, triangle, n, dp) << endl;

    // Tabulation
    cout << minSumPaths(0, 0, triangle, n) << endl;

    // Space Optimization
    cout << minSumPath(0, 0, triangle, n) << endl;

    return 0;
}