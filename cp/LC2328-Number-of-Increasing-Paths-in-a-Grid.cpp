#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findPaths(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp, int drow[], int dcol[])
    {
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int curr = grid[row][col];
        int cntPath = 1;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow < 0 || nrow >= grid.size() || ncol < 0 || ncol >= grid[0].size())
            {
                continue;
            }
            else if (curr <= grid[nrow][ncol])
            {
                continue;
            }
            cntPath = (cntPath + findPaths(nrow, ncol, grid, dp, drow, dcol)) % mod;
        }
        return dp[row][col] = cntPath;
    }

public:
    int countPaths(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int totalPath = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                totalPath = (totalPath + findPaths(i, j, grid, dp, drow, dcol)) % mod;
            }
        }
        return totalPath;
    }
};

// From low -> high

/*
class Solution
{
    int findPaths(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp, int drow[], int dcol[])
    {
        if (dp[row][col] != 0)
        {
            return dp[row][col];
        }
        int curr = grid[row][col];
        int cntPath = 1;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow < 0 || nrow >= grid.size() || ncol < 0 || ncol >= grid[0].size())
            {
                continue;
            }
            else if (curr >= grid[nrow][ncol])
            {
                continue;
            }
            cntPath = (cntPath + findPaths(nrow, ncol, grid, dp, drow, dcol)) % mod;
        }
        return dp[row][col] = cntPath;
    }

public:
    int countPaths(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};

        vector<vector<int>> dp(n, vector<int>(m));
        int totalPath = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                totalPath = (totalPath + findPaths(i, j, grid, dp, drow, dcol)) % mod;
            }
        }
        return totalPath;
    }
};
*/

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
    cout << sol.countPaths(grid) << endl;

    return 0;
}