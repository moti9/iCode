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
        ll n, q;
        cin >> n >> q;
        vector<ll> xcord(n);
        vector<ll> pref(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> xcord[i];
            if (i > 0)
            {
                pref[i] = pref[i - 1] + (xcord[i] - xcord[i - 1] + 1);
            }
        }

        for (ll qs = 0; qs < q; qs++)
        {
            ll k;
            cin >> k;
            if (k > n || k == 1)
            {
                cout << 0 << "\n";
            }
            else
            {
                ll sum = 0;
            }
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