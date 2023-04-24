#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int maxChoco(int i, int j1, int j2, int n, int m, vector<vector<int>> grid)
{
    if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
    {
        return -1e8;
    }
    if (i == n - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        return grid[i][j1] + grid[i][j2];
    }
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int val = 0;
            if (j1 == j2)
            {
                val = grid[i][j1];
            }
            else
            {
                val = grid[i][j1] + grid[i][j2];
            }
            val += maxChoco(i + 1, j1 + dj1, j2 + dj2, n, m, grid);
            maxi = max(maxi, val);
        }
    }
    return maxi;
}

// Memoization
int getMaxChoco(int i, int j1, int j2, int n, int m, vector<vector<int>> grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
    {
        return -1e8;
    }
    if (i == n - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int val = 0;
            if (j1 == j2)
            {
                val = grid[i][j1];
            }
            else
            {
                val = grid[i][j1] + grid[i][j2];
            }
            val += getMaxChoco(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
            maxi = max(maxi, val);
        }
    }
    return dp[i][j1][j2] = maxi;
}

// Tabulation
int maxChocolate(int n, int m, vector<vector<int>> grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            }
            else
            {
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int val = 0;
                        if (j1 == j2)
                        {
                            val = grid[i][j1];
                        }
                        else
                        {
                            val = grid[i][j1] + grid[i][j2];
                        }
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += dp[i + 1][j1 + dj1][j2 + dj2];
                        maxi = max(maxi, val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}

// Space Optimization
int getMaxChoco(int n, int m, vector<vector<int>> grid)
{
    vector<vector<int>> dp(m, vector<int>(m, 0));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                dp[j1][j2] = grid[n - 1][j1];
            }
            else
            {
                dp[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> temp(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int val = 0;
                        if (j1 == j2)
                        {
                            val = grid[i][j1];
                        }
                        else
                        {
                            val = grid[i][j1] + grid[i][j2];
                        }
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += dp[j1 + dj1][j2 + dj2];
                        maxi = max(maxi, val);
                    }
                }
                temp[j1][j2] = maxi;
            }
        }
        dp = temp;
    }
    return dp[0][m - 1];
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
    cout << maxChoco(0, 0, m - 1, n, m, grid) << endl;

    // Memoization
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    cout << getMaxChoco(0, 0, m - 1, n, m, grid, dp) << endl;

    // Tabulation
    cout << maxChocolate(n, m, grid) << endl;

    return 0;
}