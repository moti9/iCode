#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Gridy approach
void solve(int r, int c, int path, vector<vector<int>> &grid, int &mini)
{
    if (r < 0 || c < 0)
    {
        return;
    }
    if (r == 0 && c == 0)
    {
        mini = min(mini, path + grid[0][0]);
        return;
    }
    // left
    if (c - 1 >= 0)
    {
        solve(r, c - 1, path + grid[r][c], grid, mini);
    }
    // up
    if (r - 1 >= 0)
    {
        solve(r - 1, c, path + grid[r][c], grid, mini);
    }
    return;
}
class Solution
{
    int solve(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (r < 0 || c < 0)
        {
            return 0;
        }
        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }
        int up = 1e5, left = 1e5;
        // left
        // if (c - 1 >= 0)
        // {
        left = grid[r][c] + solve(r, c - 1, grid, dp);
        // }
        // up
        // if (r - 1 >= 0)
        // {
        up = grid[r][c] + solve(r - 1, c, grid, dp);
        // }
        return dp[r][c] = min(left, up);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int mini = 1e5;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        solve(m - 1, n - 1, grid, dp);
        return dp[0][0];
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[m][n];
        }
    }
    Solution sol;
    cout << sol.minPathSum(grid) << endl;

    return 0;
}