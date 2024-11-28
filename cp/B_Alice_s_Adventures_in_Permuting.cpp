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
        ll n, b, c;
        cin >> n >> b >> c;
        if (b == 0)
        {
            if (c >= n)
            {
                cout << n << "\n";
            }
            else if ((c == n - 1) || (c == n - 2))
            {
                cout << n - 1 << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else
        {
            bool no_sol = true;
            ll ans = 0;
            ll pos = c;
            if (pos > n)
            {
                ans += n;
            }
            else
            {
                if (b == 1)
                {
                    if (c == 0)
                        cout << 0 << "\n";
                    else
                    {
                        cout << c << "\n";
                    }
                    no_sol = false;
                }
                else
                {
                    ans += c;
                    ll diff = n - pos;
                    if (diff % b == 0)
                    {
                        ans += (diff / b) * (b - 1);
                    }
                    else
                    {
                        ans += (diff / b) * (b - 1) + (diff % b - 1);
                    }
                }
            }
            if (no_sol)
                cout << ans << "\n";
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