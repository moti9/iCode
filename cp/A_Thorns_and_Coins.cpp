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

        // vector<int> dp(n);
        // dp[0] = s[0] == '@';
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans += s[i] == '@';
            if (s[i] == '*' && s[i - 1] == '*')
                break;
            // if (s[i] == '@')
            // {
            //     dp[i] = max(dp[i], dp[i - 1] + 1);
            //     if (i > 1)
            //     {
            //         dp[i] = max(dp[i], dp[i - 2] + 1);
            //         if (s[i - 1] == '*' && s[i - 2] == '*')
            //         {
            //             break;
            //         }
            //     }
            //     ans = max(ans, dp[i]);
            // }
        }
        cout << ans << "\n";
    }
    return 0;
}