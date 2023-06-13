#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(3^N+3^N)
// SC- O(N)

class Solution
{
    int getMaxChoco(int row, int col1, int col2, vector<vector<int>> &grid)
    {
        if (col1 < 0 || col2 < 0 || col1 >= grid[0].size() || col2 >= grid[0].size())
        {
            return -1e8;
        }

        if (row == grid.size() - 1)
        {
            if (col1 == col2)
                return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }
        int maxChoco = 0;
        for (int dcol1 = -1; dcol1 <= 1; dcol1 += 1)
        {
            for (int dcol2 = -1; dcol2 <= 1; dcol2 += 1)
            {
                int val = 0;
                if (col1 == col2)
                {
                    val = grid[row][col1];
                }
                else
                {
                    val = grid[row][col1] + grid[row][col2];
                }
                val += getMaxChoco(row + 1, col1 + dcol1, col2 + dcol2, grid);
                maxChoco = max(maxChoco, val);
            }
        }
        return maxChoco;
    }

public:
    int maximumChocolates(int r, int c, vector<vector<int>> &grid)
    {
        return getMaxChoco(0, 0, c - 1, grid);
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
    cout << sol.maximumChocolates(n, m, grid) << endl;

    return 0;
}