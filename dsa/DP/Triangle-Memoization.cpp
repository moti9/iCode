#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(N+N*N)

class Solution
{
    int minPathSum(int row, int col, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
    {
        if (row >= n || col >= triangle[row].size())
        {
            return 1e9;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        if (row == n - 1)
        {
            return triangle[row][col];
        }
        int down = triangle[row][col] + minPathSum(row + 1, col, triangle, n, dp);
        int diag = triangle[row][col] + minPathSum(row + 1, col + 1, triangle, n, dp);
        return dp[row][col] = min(down, diag);
    }

public:
    int minimumPathSum(vector<vector<int>> &triangle, int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minPathSum(0, 0, triangle, n, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle;
    for (int i = 0; i < n; i++)
    {
        vector<int> row(i + 1);
        for (int j = 0; j <= i; j++)
        {
            cin >> row[j];
        }
        triangle.push_back(row);
    }

    Solution sol;
    cout << sol.minimumPathSum(triangle, n) << endl;

    return 0;
}