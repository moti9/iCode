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
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        unordered_map<ll, bool> mk;
        mk[1] = true;
        for (ll i = k; i <= 1e9;)
        {
            mk[i] = true;
            if (i > 1e9 / k)
                break;
            i *= k;
        }
        ll cnt = 0;
        for (ll x = l1; x <= r1; x++)
        {
            for (ll y = l2; y <= r2; y++)
            {
                if (mk[y / x])
                {
                    cnt += 1;
                }
            }
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