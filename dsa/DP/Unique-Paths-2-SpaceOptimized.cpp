#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(M+M)

class Solution
{
public:
    int mazeObstacles(int n, int m, vector<vector<int>> &mat)
    {
        vector<int> dp(m, 0);
        for (int row = 0; row < n; row++)
        {
            vector<int> curr(m, 0);
            for (int col = 0; col < m; col++)
            {
                if (mat[row][col] == -1)
                {
                    curr[col] = 0;
                }
                else if (row == 0 && col == 0)
                {
                    curr[col] = 1;
                }
                else
                {
                    int up = 0;
                    if (row > 0 && mat[row][col] != -1)
                    {
                        up = dp[col];
                        up %= mod;
                    }
                    int left = 0;
                    if (col > 0 && mat[row][col] != -1)
                    {
                        left = curr[col - 1];
                        left %= mod;
                    }
                    curr[col] = (up + left) % mod;
                }
            }
            dp = curr;
        }
        return dp[m - 1];
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