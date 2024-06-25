#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int j, int n, int rx, int ry, int px, int py, string &op, string &s, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return (rx == px) && (ry == py);
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == 'N')
    {
        op.push_back('R');
        if (solve(i + 1, 0, n, rx, ry + 1, px, py, op, s, dp))
        {
            return (dp[i][0] = 1);
        }
        op.pop_back();

        op.push_back('P');
        if (solve(i + 1, 1, n, rx, ry, px, py + 1, op, s, dp))
        {
            return (dp[i][1] = 1);
        }
        op.pop_back();
    }
    else if (s[i] == 'S')
    {
        op.push_back('R');
        if (solve(i + 1, 0, n, rx, ry - 1, px, py, op, s, dp))
        {
            return (dp[i][0] = 1);
        }
        op.pop_back();

        op.push_back('P');
        if (solve(i + 1, 1, n, rx, ry, px, py - 1, op, s, dp))
        {
            return (dp[i][1] = 1);
        }
        op.pop_back();
    }
    else if (s[i] == 'E')
    {
        op.push_back('R');
        if (solve(i + 1, 0, n, rx + 1, ry, px, py, op, s, dp))
        {
            return (dp[i][0] = 1);
        }
        op.pop_back();

        op.push_back('P');
        if (solve(i + 1, 1, n, rx, ry, px + 1, py, op, s, dp))
        {
            return (dp[i][1] = 1);
        }
        op.pop_back();
    }
    else
    {
        op.push_back('R');
        if (solve(i + 1, 0, n, rx - 1, ry, px, py, op, s, dp))
        {
            return (dp[i][0] = 1);
        }
        op.pop_back();

        op.push_back('P');
        if (solve(i + 1, 1, n, rx, ry, px - 1, py, op, s, dp))
        {
            return (dp[i][1] = 1);
        }
        op.pop_back();
    }
    return dp[i][j] = false;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<vector<int>> dp(n, vector<int>(2, -1));
        string op = "";
        if (solve(0, 0, n, 0, 0, 0, 0, op, s, dp))
            cout << op << "\n";
        else
            cout << "NO\n";
    }
    return 0;
}
