#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N) -> Not exact as triangle
// SC- O(N+N)

class Solution
{
public:
    int minimumPathSum(vector<vector<int>> &triangle, int n)
    {
        vector<int> dp(n);
        for (int col = 0; col < n; col++)
        {
            dp[col] = triangle[n - 1][col];
        }
        for (int row = n - 2; row >= 0; row--)
        {
            vector<int> curr(n);
            for (int col = row; col >= 0; col--)
            {
                int down = triangle[row][col] + dp[col];
                int diag = triangle[row][col] + dp[col + 1];
                curr[col] = min(down, diag);
            }
            dp = curr;
        }
        return dp[0];
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