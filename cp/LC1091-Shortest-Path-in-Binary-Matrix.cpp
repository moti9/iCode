#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] || grid[n - 1][m - 1])
        {
            return -1;
        }
        if (n == 1 && m == 1 && grid[0][0] == 0)
        {
            return 1;
        }
        vector<vector<int>> vis(n, vector<int>(m));
        queue<pair<pair<int, int>, int>> pos_path;
        pos_path.push({{0, 0}, 1});
        vis[0][0] = 1;
        while (!pos_path.empty())
        {
            auto p = pos_path.front().first;
            int row = p.first;
            int col = p.second;
            int path = pos_path.front().second;
            pos_path.pop();
            for (int drow = -1; drow <= 1; drow++)
            {
                for (int dcol = -1; dcol <= 1; dcol++)
                {
                    int nrow = row + drow;
                    int ncol = col + dcol;
                    if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                    {
                        continue;
                    }
                    else if (vis[nrow][ncol] || grid[nrow][ncol])
                    {
                        continue;
                    }
                    if (nrow == n - 1 && ncol == m - 1)
                    {
                        return path + 1;
                    }
                    vis[nrow][ncol] = 1;
                    pos_path.push({{nrow, ncol}, path + 1});
                }
            }
        }
        return -1;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(m, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}