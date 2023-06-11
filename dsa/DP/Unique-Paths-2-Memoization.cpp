#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(pathLen) -> O(N+M-2) + O(N*M)

class Solution
{
    int countUniquePaths(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (row < 0 || col < 0)
        {
            return 0;
        }
        if (row >= 0 && col >= 0 && matrix[row][col] == -1)
        {
            return 0;
        }
        if (row == 0 && col == 0)
        {
            return 1;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        int up = countUniquePaths(row - 1, col, matrix, dp);
        up %= mod;
        int left = countUniquePaths(row, col - 1, matrix, dp);
        left %= mod;

        return dp[row][col] = (up + left) % mod;
    }

public:
    int mazeObstacles(int n, int m, vector<vector<int>> &mat)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countUniquePaths(n - 1, m - 1, mat, dp);
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