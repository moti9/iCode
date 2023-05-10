#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Combinatorics Solution
// TC- O(N-1)|O(M-1)
// SC- O(1)
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int N = n + m - 2;
        int r = m - 1;
        double res = 1;

        for (int i = 1; i <= r; i++)
            res = res * (N - r + i) / i;
        return (int)res;
    }
};

// Dp Solution
// TC- O(N*M)
// SC- O(N*M)

/*
class Solution
{
    int countPath(int row, int col, int n, int m, vector<vector<int>> &dp)
    {
        if (row >= n || col >= m)
            return 0;
        if (row == n - 1 && col == m - 1)
            return 1;
        if (dp[row][col] != -1)
            return dp[row][col];
        return dp[row][col] = countPath(row + 1, col, n, m, dp) + countPath(row, col + 1, n, m, dp);
    }

public:
    int uniquePaths(int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countPath(0, 0, n, m, dp);
    }
};
*/

// Recursive Solution
// TC- The time comp[lexity of this recursive solution is exponential.
// SC- As we are using stack space for recursion so the space complexity will also be exponential.
/*
class Solution
{
    int countPath(int row, int col, int n, int m)
    {
        if (row >= n || col >= m)
            return 0;
        if (row == n - 1 && col == m - 1)
            return 1;
        return countPath(row + 1, col, n, m) + countPath(row, col + 1, n, m);
    }

public:
    int uniquePaths(int n, int m)
    {
        return countPath(0, 0, n, m);
    }
};
*/

int main()
{
    int n, m;
    cin >> n >> m;

    Solution sol;
    cout << sol.uniquePaths(n, m) << endl;

    return 0;
}