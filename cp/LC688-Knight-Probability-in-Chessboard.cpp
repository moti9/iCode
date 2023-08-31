#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    double findProbability(int k, int row, int col, int n, vector<vector<int>> &dirs, vector<vector<vector<double>>> &dp)
    {
        if (k == 0)
        {
            return 1.0;
        }
        if (dp[k][row][col] != -1)
        {
            return dp[k][row][col];
        }
        double totalProb = 0.0;
        for (int i = 0; i < 8; i++)
        {
            int nrow = row + dirs[i][0];
            int ncol = col + dirs[i][1];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n)
            {
                totalProb += findProbability(k - 1, nrow, ncol, n, dirs, dp) / (double)8.0;
            }
        }
        return dp[k][row][col] = totalProb;
    }

public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<int>> dirs = {{-1, -2}, {1, -2}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, -1.0)));
        return findProbability(k, row, column, n, dirs, dp);
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    int row, col;
    cin >> row >> col;

    Solution sol;
    cout << sol.knightProbability(n, k, row, col) << endl;

    return 0;
}