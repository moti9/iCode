#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int penalty = 0;
        for (int i = 0; i < n; i++)
        {
            penalty += (s[i] == '+' ? 1 : -1);
        }

        cout << abs(penalty) << "\n";
        
        // vector<int> cum_sum(n + 1);
        // for (int i = 1; i <= n; i++)
        // {
        //     cum_sum[i] = cum_sum[i - 1] + ((s[i - 1] == '+') ? 1 : -1);
        // }

        // vector<int> dp(n + 1, INT_MAX);
        // dp[0] = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 0; j < i; j++)
        //     {
        //         dp[i] = min(dp[i], dp[j] + abs(cum_sum[i] - cum_sum[j]));
        //     }
        // }

        // cout << dp[n] << "\n";
    }
    return 0;
}