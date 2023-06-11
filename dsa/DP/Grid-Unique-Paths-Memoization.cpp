#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(pathLen) -> O(M+N-2) + O(N*M)

/*
    In problem stated we can move only right and down(from top to bottom),
    as we are moving top to bottom so we'll move up and left(reverse)
*/

class Solution
{
    int countPaths(int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 && col == 0)
        {
            return 1;
        }
        if (row < 0 || col < 0)
        {
            return 0;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int up = countPaths(row - 1, col, dp);
        int left = countPaths(row, col - 1, dp);

        return dp[row][col] = up + left;
    }

public:
    int uniquePaths(int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countPaths(n - 1, m - 1, dp);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    Solution sol;
    cout << sol.uniquePaths(n, m);

    return 0;
}