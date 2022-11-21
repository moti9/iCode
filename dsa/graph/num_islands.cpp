#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int n, int m)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty())
    {
        row = q.front().first;
        col = q.front().second;
        q.pop();

        for (int drow = -1; drow <= 1; drow++)
        {
            for (int dcol = -1; dcol <= 1; dcol++)
            {
                int nrow = row + drow;
                int ncol = col + dcol;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

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
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] && grid[row][col] == 1)
            {
                count += 1;
                bfs(row, col, grid, vis, n, m);
            }
        }
    }
    cout << count << "\n";

    return 0;
}