#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0 && !vis[i][j] && bfs(i, j, n, m, grid, vis))
                    ct++;
            }
        }
        return ct;
    }

    bool bfs(int r, int c, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 2;
        bool island = true;

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
                    island = false;
                }
                else if (grid[nr][nc] == 0 && !vis[nr][nc])
                {
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }
        return island;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    cout << sol.closedIsland(grid) << endl;

    return 0;
}