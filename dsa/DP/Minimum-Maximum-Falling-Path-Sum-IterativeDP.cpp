#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(N*M)

class Solution
{
public:
    int getMaxPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for (int col = 0; col < m; col++)
        {
            dp[0][col] = matrix[0][col];
        }
        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                int up = matrix[row][col] + dp[row - 1][col];
                int leftDiag = -1e7;
                if (col - 1 >= 0)
                {
                    leftDiag = matrix[row][col] + dp[row - 1][col - 1];
                }
                int rightDiag = -1e7;
                if (col + 1 < m)
                {
                    rightDiag = matrix[row][col] + dp[row - 1][col + 1];
                }
                dp[row][col] = max({up, leftDiag, rightDiag});
            }
        }
        int maxPath = -1e7;
        for (int col = 0; col < m; col++)
        {
            maxPath = max(maxPath, dp[n - 1][col]);
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