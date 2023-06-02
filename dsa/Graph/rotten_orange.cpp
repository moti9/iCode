#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m));
    queue<pair<pair<int, int>, int>> q;
    int ctfresh = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 2)
            {
                vis[i][j] = 2;
                q.push({{i, j}, 0});
            }
            else
            {
                vis[i][j] = 0;
            }
            if (grid[i][j] == 1)
            {
                ctfresh += 1;
            }
        }
    }
    int tm = 0;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
                ctfresh -= 1;
            }
        }
    }
    if (ctfresh != 0)
    {
        cout << -1;
    }
    else
    {
        cout << tm;
    }

    return 0;
}