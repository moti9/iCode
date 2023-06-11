#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N*M)
// SC- O(N+M-2)

class Solution
{
    int minPath(int row, int col, vector<vector<int>> &grid)
    {
        if (row < 0 || col < 0)
        {
            return 1e9;
        }
        if (row == 0 && col == 0)
        {
            return grid[row][col];
        }
        int up = grid[row][col] + minPath(row - 1, col, grid);
        int left = grid[row][col] + minPath(row, col - 1, grid);

        return min(up, left);
    }

public:
    int minSumPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        return minPath(n - 1, m - 1, grid);
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