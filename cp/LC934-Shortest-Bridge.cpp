#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// BFS+DFS
// TC- O(N*N)
// SC- O(N*N)
class Solution
{
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, queue<pair<int, int>> &island, int drow[], int dcol[])
    {
        vis[row][col] = 1;
        island.push({row, col});
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < 0 || nrow >= grid.size() || ncol < 0 || ncol >= grid.size())
            {
                continue;
            }
            else if (vis[nrow][ncol] || grid[nrow][ncol] == 0)
            {
                continue;
            }
            dfs(nrow, ncol, grid, vis, island, drow, dcol);
        }
    }

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int row = -1, col = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        vector<vector<int>> vis(n, vector<int>(n));
        queue<pair<int, int>> island;
        int drow[4] = {0, 0, -1, 1};
        int dcol[4] = {-1, 1, 0, 0};
        dfs(row, col, grid, vis, island, drow, dcol);
        int bridge = 0;
        while (!island.empty())
        {
            int num_island = island.size();
            for (int i = 0; i < num_island; i++)
            {
                auto pos = island.front();
                island.pop();
                int r = pos.first;
                int c = pos.second;
                for (int j = 0; j < 4; j++)
                {
                    int nr = r + drow[j];
                    int nc = c + dcol[j];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                        continue;
                    else if (vis[nr][nc])
                        continue;
                    if (grid[nr][nc] == 1)
                    {
                        return bridge;
                    }
                    vis[nr][nc] = 1;
                    island.push({nr, nc});
                }
            }
            bridge += 1;
        }
        return bridge;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution sol;

    cout << sol.shortestBridge(grid) << endl;

    return 0;
}