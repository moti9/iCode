#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> fn_pairs;

    int dp[n + 1][m + 1];

    for (int i = 0; i < k; i++)
    {
        char a, b;
        cin >> a >> b;
        int x = (int)(a - 'a') + 1;
        int y = (int)(b - 'a') + 1;
        fn_pairs.push_back({x, y});
    }

    for (int i = 1; i <= m; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = 0;
            for (int k = 1; k <= m; k++)
            {
                bool valid = true;
                for (const auto &forbidden : fn_pairs)
                {
                    if (forbidden.first == k && forbidden.second == j)
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= m; j++)
    {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
