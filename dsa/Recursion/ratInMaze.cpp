#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void findPath(int i, int j, int n, vector<vector<int>> maze, vector<string> &ans, string moves, vector<vector<int>> &vis)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(moves);
        return;
    }
    // Down
    if (i + 1 < n && !vis[i + 1][j] && maze[i + 1][j] == 1)
    {
        vis[i + 1][j] = 1;
        findPath(i + 1, j, n, maze, ans, moves + 'D', vis);
        vis[i + 1][j] = 0;
    }
    // Left
    if (j - 1 >= 0 && !vis[i][j - 1] && maze[i][j - 1] == 1)
    {
        vis[i][j - 1] = 1;
        findPath(i, j - 1, n, maze, ans, moves + 'L', vis);
        vis[i][j - 1] = 0;
    }
    // Right
    if (j + 1 < n && !vis[i][j + 1] && maze[i][j + 1] == 1)
    {
        vis[i][j + 1] = 1;
        findPath(i, j + 1, n, maze, ans, moves + 'R', vis);
        vis[i][j + 1] = 0;
    }
    // Up
    if (i - 1 >= 0 && !vis[i - 1][j] && maze[i - 1][j] == 1)
    {
        vis[i - 1][j] = 1;
        findPath(i - 1, j, n, maze, ans, moves + 'U', vis);
        vis[i - 1][j] = 0;
    }
}

// Approach-2
void findPaths(int i, int j, int n, vector<vector<int>> maze, vector<string> &ans, string moves, vector<vector<int>> &vis, int row[], int col[], char dir[])
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(moves);
        return;
    }
    for (int ind = 0; ind < 4; ind++)
    {
        int nrow = i + row[ind];
        int ncol = j + col[ind];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol] && maze[nrow][ncol] == 1)
        {
            vis[nrow][ncol] = 1;
            findPaths(nrow, ncol, n, maze, ans, moves + dir[ind], vis, row, col, dir);
            vis[nrow][ncol] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(n, false));
    vector<string> ans;
    if (maze[0][0] == 1)
    {
        // findPath(0, 0, n, maze, ans, "", vis);

        int row[4] = {1, 0, 0, -1};
        int col[4] = {0, -1, 1, 0};
        char dir[4] = {'D', 'L', 'R', 'U'};
        findPaths(0, 0, n, maze, ans, "", vis, row, col, dir);
    }
    for (auto x : ans)
    {
        cout << x << endl;
    }

    return 0;
}