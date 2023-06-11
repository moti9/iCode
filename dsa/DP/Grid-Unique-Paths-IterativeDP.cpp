#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(N*M)

/*
    In problem stated we can move only right and down(from top to bottom),
    as we are moving top to bottom so we'll move up and left(reverse)
*/

class Solution
{

public:
    int uniquePaths(int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (row == 0 && col == 0)
                    continue;
                int up = 0;
                if (row > 0)
                {
                    up = dp[row - 1][col];
                }
                int left = 0;
                if (col > 0)
                {
                    left = dp[row][col - 1];
                }
                dp[row][col] = up + left;
            }
        }
        return dp[n - 1][m - 1];
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