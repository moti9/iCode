#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(M+M)

/*
    In problem stated we can move only right and down(from top to bottom),
    as we are moving top to bottom so we'll move up and left(reverse)
*/

class Solution
{

public:
    int uniquePaths(int n, int m)
    {
        vector<int> dp(m, 0);
        for (int row = 0; row < n; row++)
        {
            vector<int> curr(m, 0);
            for (int col = 0; col < m; col++)
            {
                if (row == 0 && col == 0)
                {
                    curr[col] = 1;
                    continue;
                }
                int up = 0;
                if (row > 0)
                {
                    up = dp[col];
                }
                int left = 0;
                if (col > 0)
                {
                    left = curr[col - 1];
                }
                curr[col] = up + left;
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

    Solution sol;
    cout << sol.uniquePaths(n, m);

    return 0;
}