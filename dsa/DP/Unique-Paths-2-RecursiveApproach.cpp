#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N*M)
// SC- O(pathLen) -> O(N+M-2)

class Solution
{
    int countUniquePaths(int row, int col, vector<vector<int>> &matrix)
    {
        if (row < 0 || col < 0)
        {
            return 0;
        }
        if (row >= 0 && col >= 0 && matrix[row][col] == -1)
        {
            return 0;
        }
        if (row == 0 && col == 0)
        {
            return 1;
        }

        int up = countUniquePaths(row - 1, col, matrix);
        up %= mod;
        int left = countUniquePaths(row, col - 1, matrix);
        left %= mod;

        return (up + left) % mod;
    }

public:
    int mazeObstacles(int n, int m, vector<vector<int>> &mat)
    {
        return countUniquePaths(n - 1, m - 1, mat);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    Solution sol;
    cout << sol.mazeObstacles(n, m, matrix) << endl;

    return 0;
}