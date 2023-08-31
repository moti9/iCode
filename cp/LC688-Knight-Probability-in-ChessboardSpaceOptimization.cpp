#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<int>> dirs = {{-1, -2}, {1, -2}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};
        vector<vector<double>> prevDp(vector<vector<double>>(n, vector<double>(n, 0.0)));
        vector<vector<double>> currDp(vector<vector<double>>(n, vector<double>(n, 0.0)));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                prevDp[i][j] = 1.0;
            }
        }

        for (int s = 1; s <= k; ++s)
        {
            for (int r = 0; r < n; ++r)
            {
                for (int c = 0; c < n; ++c)
                {
                    currDp[r][c] = 0.0;
                    for (int i = 0; i < 8; ++i)
                    {
                        int nrow = r + dirs[i][0];
                        int ncol = c + dirs[i][1];

                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n)
                        {
                            currDp[r][c] += prevDp[nrow][ncol] / 8.0;
                        }
                    }
                }
            }
            prevDp = currDp;
        }

        return prevDp[row][column];
    }
};

/*
class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<int>> dirs = {{-1, -2}, {1, -2}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};
        vector<vector<double>> prevDp(vector<vector<double>>(n, vector<double>(n, 0.0)));
        vector<vector<double>> currDp(vector<vector<double>>(n, vector<double>(n, 0.0)));

        prevDp[row][column] = 1.0;

        for (int moves = 1; moves <= k; moves++)
        {
            for (int currRow = 0; currRow < n; currRow++)
            {
                for (int currCol = 0; currCol < n; currCol++)
                {
                    currDp[currRow][currCol] = 0.0;
                    for (int ind = 0; ind < 8; ind++)
                    {
                        int prevRow = currRow - dirs[ind][0];
                        int prevCol = currCol - dirs[ind][1];
                        if (prevRow >= 0 && prevRow < n && prevCol >= 0 && prevCol < n)
                        {
                            currDp[currRow][currCol] += (prevDp[prevRow][prevCol] / (double)8.0);
                        }
                    }
                }
            }
            prevDp = currDp;
        }
        double totalProb = 0.0;

        for (int currRow = 0; currRow < n; currRow++)
        {
            for (int currCol = 0; currCol < n; currCol++)
            {
                totalProb += prevDp[currRow][currCol];
            }
        }

        return totalProb;
    }
};

*/

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