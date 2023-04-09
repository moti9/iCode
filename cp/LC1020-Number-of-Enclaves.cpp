#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void bfs(int r, int c, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 2;

        while (!q.empty())
        {
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nr = r + row[i];
                int nc = c + col[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                {
                    continue;
                }
                else if (grid[nr][nc] == 1 && !vis[nr][nc])
                {
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }
        return;
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        for (int i = 0; i < n; ++i)
        {
            if (grid[i][0] == 1 && !vis[i][0])
            {
                bfs(i, 0, n, m, grid, vis);
            }
            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
            {
                bfs(i, m - 1, n, m, grid, vis);
            }
        }

        for (int j = 0; j < m; ++j)
        {
            if (grid[0][j] == 1 && !vis[0][j])
            {
                bfs(0, j, n, m, grid, vis);
            }
            if (grid[n - 1][j] == 1 && !vis[n - 1][j])
            {
                bfs(n - 1, j, n, m, grid, vis);
            }
        }
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                    ct++;
            }
        }
        return ct;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    Solution sol;
    cout << sol.numEnclaves(grid) << endl;

    return 0;
}