#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int solve(int i, int j, int x, int y, vector<vector<int>> &mat, map<pair<int, pair<int, int>>, int> &dp)
{
    int n = mat.size();
    int m = mat[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == -1)
    {
        return INT_MIN;
    }
    if (x < 0 || y < 0 || x >= n || y >= m || mat[x][y] == -1)
    {
        return INT_MIN;
    }
    if (i == n - 1 && x == n - 1 && j == m - 1 && y == m - 1)
    {
        return (mat[i][j] == 1) ? 1 : 0;
    }

    if (dp.find({i, {j, x}}) != dp.end())
    {
        return dp[{i, {j, x}}];
    }

    int cnt = 0;
    cnt += ((i == x && j == y) ? (mat[i][j] == 1) : (mat[i][j] == 1) + (mat[x][y] == 1));

    int op1 = solve(i + 1, j, x + 1, y, mat, dp);
    int op2 = solve(i, j + 1, x, y + 1, mat, dp);
    int op3 = solve(i + 1, j, x, y + 1, mat, dp);
    int op4 = solve(i, j + 1, x + 1, y, mat, dp);

    cnt += max(op1, max(op2, max(op3, op4)));

    return dp[{i, {j, x}}] = cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    map<pair<int, pair<int, int>>, int> dp;
    int ans = solve(0, 0, 0, 0, matrix, dp);
    if (ans >= 0)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
