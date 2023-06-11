#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(N*M)

class Solution
{
public:
    int minSumPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (row == 0 && col == 0)
                {
                    dp[row][col] = grid[0][0];
                }
                else
                {
                    int up = 1e9;
                    if (row > 0)
                    {

                        up = grid[row][col] + dp[row - 1][col];
                    }
                    int left = 1e9;
                    if (col > 0)
                    {
                        left = grid[row][col] + dp[row][col - 1];
                    }

                    dp[row][col] = min(up, left);
                }
            }
        }
        return dp[n - 1][m - 1];
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