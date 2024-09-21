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
    // cin>>ttt;
    while (ttt--)
    {
        string s;
        cin >> s;

        int n = s.length();
        vector<int> dp(n + 1);

        for (int ind1 = 1, ind2 = 0; ind1 < n; ind1++)
        {
            while (ind2 > 0 && s[ind1] != s[ind2])
            {
                ind2 = dp[ind2 - 1];
            }
            if (s[ind1] == s[ind2])
                ind2++;
            dp[ind1] = ind2;
        }
        if (dp[n - 1] <= n / 2)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << s.substr(0, dp[n - 1]) << "\n";
        }
    }
    return 0;
}
/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/