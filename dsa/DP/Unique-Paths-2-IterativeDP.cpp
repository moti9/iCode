#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(N*M)

class Solution
{
public:
    int mazeObstacles(int n, int m, vector<vector<int>> &mat)
    {
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = 1;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (mat[row][col] == -1)
                {
                    dp[row][col] = 0;
                }
                else if (row == 0 && col == 0)
                {
                    dp[row][col] = 1;
                }
                else
                {
                    int up = 0;
                    if (row > 0 && mat[row][col] != -1)
                    {
                        up = dp[row - 1][col];
                        up %= mod;
                    }
                    int left = 0;
                    if (col > 0 && mat[row][col] != -1)
                    {
                        left = dp[row][col - 1];
                        left %= mod;
                    }
                    dp[row][col] = (up + left) % mod;
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
    vector<vector<int>> matrix(n, vector<int>(m));

    Solution sol;
    cout << sol.mazeObstacles(n, m, matrix) << endl;

    return 0;
}