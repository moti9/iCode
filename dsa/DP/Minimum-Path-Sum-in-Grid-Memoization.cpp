#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(N+M-2)+O(N*M)

class Solution
{
    int minPath(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (row < 0 || col < 0)
        {
            return 1e9;
        }
        if (row == 0 && col == 0)
        {
            return grid[row][col];
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        int up = grid[row][col] + minPath(row - 1, col, grid, dp);
        int left = grid[row][col] + minPath(row, col - 1, grid, dp);

        return min(up, left);
    }

public:
    int minSumPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minPath(n - 1, m - 1, grid, dp);
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
    cout << sol.minSumPath(grid) << endl;

    return 0;
}