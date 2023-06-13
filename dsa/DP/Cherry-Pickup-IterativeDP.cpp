#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M*M*9)
// SC- O(N*M*M)

class Solution
{
public:
    int maximumChocolates(int r, int c, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c)));
        // Base Case
        for (int col1 = 0; col1 < c; col1++)
        {
            for (int col2 = 0; col2 < c; col2++)
            {
                if (col1 == col2)
                {
                    dp[r - 1][col1][col2] = grid[r - 1][col1];
                }
                else
                {
                    dp[r - 1][col1][col2] = grid[r - 1][col1] + grid[r - 1][col2];
                }
            }
        }
        for (int row = r - 2; row >= 0; row--)
        {
            for (int col1 = 0; col1 < c; col1++)
            {
                for (int col2 = 0; col2 < c; col2++)
                {
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
                            int ncol1 = col1 + dcol1;
                            int ncol2 = col2 + dcol2;
                            if (ncol1 >= 0 && ncol1 < c && ncol2 >= 0 && ncol2 < c)
                            {
                                val += dp[row + 1][ncol1][ncol2];
                            }
                            else
                            {
                                val += (-1e8);
                            }
                            maxChoco = max(maxChoco, val);
                        }
                    }
                    dp[row][col1][col2] = maxChoco;
                }
            }
        }
        return dp[0][0][c - 1];
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