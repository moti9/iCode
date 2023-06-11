#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(N*M+N)

class Solution
{
    int getPathSum(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (col < 0 || col >= matrix[0].size())
        {
            return -1e7;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        if (row == 0)
        {
            return matrix[row][col];
        }
        int up = matrix[row][col] + getPathSum(row - 1, col, matrix, dp);
        int leftDiag = matrix[row][col] + getPathSum(row - 1, col - 1, matrix, dp);
        int rightDiag = matrix[row][col] + getPathSum(row - 1, col + 1, matrix, dp);

        return dp[row][col] = max(up, max(leftDiag, rightDiag));
    }

public:
    int getMaxPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int maxPath = -1e7;
        for (int i = 0; i < m; i++)
        {
            maxPath = max(maxPath, getPathSum(n - 1, i, matrix, dp));
        }
        return maxPath;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    cout << sol.getMaxPathSum(matrix) << endl;

    return 0;
}