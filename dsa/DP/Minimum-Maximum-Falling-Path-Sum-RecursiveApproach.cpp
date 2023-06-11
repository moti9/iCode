#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(3^N)
// SC- O(N)

class Solution
{
    int getPathSum(int row, int col, vector<vector<int>> &matrix)
    {
        if (col < 0 || col >= matrix[0].size())
        {
            return -1e7;
        }
        if (row == 0)
        {
            return matrix[row][col];
        }

        int up = matrix[row][col] + getPathSum(row - 1, col, matrix);
        int leftDiag = matrix[row][col] + getPathSum(row - 1, col - 1, matrix);
        int rightDiag = matrix[row][col] + getPathSum(row - 1, col + 1, matrix);

        return max(up, max(leftDiag, rightDiag));
    }

public:
    int getMaxPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxPath = -1e7;
        for (int i = 0; i < m; i++)
        {
            maxPath = max(maxPath, getPathSum(n - 1, i, matrix));
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