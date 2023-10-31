#include <bits/stdc++.h>
using namespace std;

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

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n, -1)));

    dp[n - 1][m - 1][n - 1] = (matrix[n - 1][m - 1] == 1) ? 1 : 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            for (int x = n - 1; x >= 0; x--)
            {
                int y = i + j - x;
                if (y < 0 || y >= m)
                    continue;

                if (i < n - 1)
                {
                    dp[i][j][x] = max(dp[i][j][x], dp[i + 1][j][x]);
                }
                if (j < m - 1)
                {
                    dp[i][j][x] = max(dp[i][j][x], dp[i][j + 1][x]);
                }
                if (x < n - 1)
                {
                    dp[i][j][x] = max(dp[i][j][x], dp[i][j][x + 1]);
                }
                if (i < n - 1 && x < n - 1)
                {
                    dp[i][j][x] = max(dp[i][j][x], dp[i + 1][j][x + 1]);
                }

                dp[i][j][x] += (i == x) ? matrix[i][j] : matrix[i][j] + matrix[x][y];
            }
        }
    }

    int result = dp[0][0][0];

    if (result < 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}
