#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int dfs(int row, int col, vector<vector<int>> &lack, vector<vector<int>> &vis, int n, int m, int drow[], int dcol[])
{
    vis[row][col] = 1;
    int depth = lack[row][col];
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
            continue;
        else if (vis[nrow][ncol] || lack[nrow][ncol] == 0)
            continue;
        depth += dfs(nrow, ncol, lack, vis, n, m, drow, dcol);
    }
    return depth;
}

void solvehere()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> lack(n, vector<int>(m));
    // queue<pair<pair<int, int>, int>> q; // row-col-total_depth
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> lack[i][j];
            // ans = max(ans, lack[i][j]);
            // if (lack[i][j] != 0)
            // {
            //     q.push({{i, j}, lack[i][j]});
            // }
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int drow[4] = {1, -1, 0, 0};
    int dcol[4] = {0, 0, -1, 1};
    // while (!q.empty())
    // {
    //     auto node = q.front();
    //     q.pop();
    //     int row = node.first.first;
    //     int col = node.first.second;
    //     int depth = node.second;
    //     ans = max(ans, depth);
    //     vis[row][col] = 1;
    //     for (int i = 0; i < 4; i++)
    //     {
    //         int nrow = row + drow[i];
    //         int ncol = col + dcol[i];
    //         if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
    //             continue;
    //         else if (vis[nrow][ncol] || lack[nrow][ncol] == 0)
    //             continue;

    //         q.push({{nrow, ncol}, depth + lack[nrow][ncol]});
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && lack[i][j] != 0)
            {
                int temp = dfs(i, j, lack, vis, n, m, drow, dcol);
                ans = max(ans, temp);
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
