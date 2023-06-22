#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void dfs(int row, int col, unordered_map<int, unordered_map<int, vector<pair<int, int>>>> &graph, int &cnt)
    {
        cnt += 1;
        for (auto pr : graph[row][col])
        {
            dfs(pr.first, pr.second, graph, cnt);
        }
    }

    void createGraph(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> adj[], vector<vector<int>> &path)
    {
        if (vis[row][col] == 1)
        {
            return;
        }
        int n = grid.size();

        vis[row][col] = 1;
        int cnt = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow < 0 || ncol < 0 || nrow >= grid.size() || ncol >= grid[0].size())
            {
                continue;
            }
            else if (vis[nrow][ncol] || grid[nrow][ncol] >= grid[row][col])
            {
                continue;
            }
            // int node = row * n + col;
            // int adjNode = nrow * n + ncol;
            // adj[node].push_back(adjNode);
            cnt += 1;
            createGraph(nrow, ncol, grid, vis, adj, path);
        }
        path[row][col] = cnt;

        return;
    }

public:
    int countPaths(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // unordered_map<int, unordered_map<int, vector<pair<int, int>>>> graph;
        vector<vector<int>> vis(n, vector<int>(m));
        vector<vector<int>> path(n, vector<int>(m));
        vector<int> adj[n * m];
        // vector<vector<int>> path(n, vector<int>(m));
        int cnt = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                createGraph(i, j, grid, vis, adj, path);
                cnt += path[i][j];
            }
        }

        return cnt;
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
    cout << sol.countPaths(grid) << endl;

    return 0;
}