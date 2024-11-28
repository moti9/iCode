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
        ll maxRange = m - (m % x);
        ll cnt = (maxRange / x) - (x < maxRange);
        if ((maxRange ^ x) >= 1 && (maxRange ^ x) <= m)
            cnt += 1;
        maxRange += x;
        if ((maxRange ^ x) >= 1 && (maxRange ^ x) <= m)
            cnt += 1;

        for (ll i = 1; i <= min(x, m); i++)
        {
            ll xorVal = x ^ i;
            cnt += (xorVal % i == 0);
        }

        if (x <= m)
            cnt -= 1;

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