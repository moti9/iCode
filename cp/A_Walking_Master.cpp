#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll calc_step(ll a, ll b, ll c, ll d)
{
    ll y_steps = abs(b - d);
    return y_steps + (a + y_steps - c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if (c <= a)
        {
            if ((d >= b && d >= (c + (b - a))))
            {
                cout << calc_step(a, b, c, d) << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else
        {
            if ((d >= b && d >= (c + (b - a))))
            {
                cout << calc_step(a, b, c, d) << "\n";
            }
            else
            {
                cout << -1 << "\n";
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