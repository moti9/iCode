#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void print(vector<vector<int>> dp)
{
    for (auto x : dp)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Recursive
int solve(int r, int c, int n, vector<vector<int>> mat, int row[], int col[])
{
    if (r >= n)
    {
        return 0;
    }
    if (c >= n || c < 0)
        return 100000;
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        int nr = row[i] + r;
        int nc = col[i] + c;
        ans = min(ans, mat[r][c] + solve(nr, nc, n, mat, row, col));
    }
    return ans;
}

// Memoization
int solve(int r, int c, int n, vector<vector<int>> mat, vector<vector<int>> &dp, int row[], int col[])
{
    if (r >= n)
    {
        return 0;
    }
    if (c >= n || c < 0)
        return 100000;
    if (dp[r][c] != 1000000)
    {
        return dp[r][c];
    }
    int ans = INT_MAX;
    for (int i = 0; i < 3; i++)
    {
        int nr = row[i] + r;
        int nc = col[i] + c;
        ans = min(ans, mat[r][c] + solve(nr, nc, n, mat, dp, row, col));
    }
    return dp[r][c] = ans;
}

// Tabulization

void solve(int n, vector<vector<int>> matrix, vector<vector<int>> &dp)
{
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            dp[i + 1][j + 1] = matrix[i][j] + min({dp[i + 2][j], dp[i + 2][j + 1], dp[i + 2][j + 2]});
        }
    }
    // print(dp);
}

void solve2(int n, vector<vector<int>> matrix, vector<vector<int>> &dp)
{
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            dp[i][j + 1] = matrix[i][j] + min({dp[i + 1][j], dp[i + 1][j + 1], dp[i + 1][j + 2]});
        }
    }
    // print(dp);
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // int row[3] = {1, 1, 1};
    // int col[3] = {-1, 0, 1};
    // int ans = INT_MAX;

    // vector<vector<int>> dp(n, vector<int>(n, 1000000));
    // vector<vector<int>> dp(n + 2, vector<int>(n + 2, 1000000));
    // for (int i = 0; i < n; i++)
    // {
    //     dp[n][i + 1] = matrix[n - 1][i];
    // }
    vector<vector<int>> dp(n, vector<int>(n + 2, 1000000));
    for (int i = 0; i < n; i++)
    {
        dp[n][i + 1] = matrix[n - 1][i];
    }
    solve(n, matrix, dp);
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        // ans = min(ans, solve(0, i, n, matrix, dp, row, col));
        // ans = min(ans, solve(0, i, n, matrix, row, col));
        // ans = min(ans, dp[1][i + 1]);
        ans = min(ans, dp[0][i + 1]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    // Tabular

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // cout << minFallingPathSum(matrix) << endl;

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 100000));
    for (int i = 0; i < n; i++)
    {
        dp[n][i + 1] = matrix[n - 1][i];
    }
    solve(n, matrix, dp);
    // print(dp);
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        // ans = min(ans, solve(0, i, n, matrix, dp, row, col));
        // ans = min(ans, solve(0, i, n, matrix, row, col));
        ans = min(ans, dp[1][i + 1]);
    }
    // END

    cout << ans << endl;
    return 0;
}