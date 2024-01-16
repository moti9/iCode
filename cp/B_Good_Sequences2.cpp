#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i < 0)
        return 0;
    int take = 0, notTake = 0;
    notTake = 0 + solve(i - 1, j, arr, dp);

    if (dp[i][j + 1] != -1)
        return dp[i][j + 1];

    if (j == -1)
    {
        take = 1 + solve(i - 1, i, arr, dp);
    }
    else if (arr[i] < arr[j])
    {
        int gcd = __gcd(arr[i], arr[j]);
        if (gcd > 1)
        {
            take = 1 + solve(i - 1, i, arr, dp);
        }
    }

    return dp[i][j + 1] = max(take, notTake);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int ans = solve(n - 1, -1, arr, dp);
        cout << ans << endl;
    }
    return 0;
}