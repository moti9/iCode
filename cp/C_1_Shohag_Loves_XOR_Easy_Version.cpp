#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        ll x, m;
        cin >> x >> m;
        ll maxRange = min(m, 2 * x);
        ll cnt = 0;
        for (ll i = 1; i <= maxRange; i++)
        {
            if (x == i)
                continue;
            ll xorVal = x ^ i;
            if ((x % xorVal == 0) || (i % xorVal == 0))
                cnt += 1;
        }
        cout << cnt << "\n";
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