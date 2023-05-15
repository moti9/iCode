#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {

        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return 0;

        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int res = 0;
        int dir[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
        for (int i = 0; i < 3; i++)
        {
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];
            if (nrow < 0 || ncol < 0 || nrow >= grid.size() || ncol >= grid[0].size())
                continue;
            else if (grid[nrow][ncol] <= grid[row][col])
            {
                continue;
            }
            res = max(res, 1 + dfs(nrow, ncol, grid, dp));
        }

        dp[row][col] = max(dp[row][col], res);
        return res;
    }

public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            res = max(res, dfs(i, 0, grid, dp));
        }
        return res;
    }
};

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

    Solution sol;
    cout << sol.maxMoves(grid) << endl;

    return 0;
}