#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll solve(int i, int j, vector<vector<ll>> &mat, vector<vector<ll>> &dp)
{
    if (i == mat.size() - 1 && j == mat[0].size() - 1)
        return mat[i][j] > 0 ? 1 : abs(mat[i][j]) + 1;

    if (i >= mat.size() || j >= mat[0].size())
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    ll down = solve(i + 1, j, mat, dp);
    ll right = solve(i, j + 1, mat, dp);

    ll needed_strength = min(down, right) - mat[i][j];
    return dp[i][j] = needed_strength <= 0 ? 1 : needed_strength;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<ll>> mat(m, vector<ll>(n));
    vector<vector<ll>> dp(m, vector<ll>(n, -1));

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];

    cout << solve(0, 0, mat, dp) << endl;
    return 0;
}
