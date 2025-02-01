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
        ll m, a, b, c;
        cin >> m >> a >> b >> c;
        ll ans = 0;
        ll row1 = m, row2 = m;
        if (a <= m)
        {
            ans += a;
            row1 -= a;
        }
        else
        {
            ans += m;
            row1 = 0;
        }
        if (b <= m)
        {
            ans += b;
            row2 -= b;
        }
        else
        {
            ans += m;
            row2 = 0;
        }
        ans += min(row1 + row2, c);
        cout << ans << "\n";
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