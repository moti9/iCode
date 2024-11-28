#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll log_a_to_base_b(ll a, ll b)
{
    return log10(a) / log10(b);
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
        ll n, k;
        cin >> n >> k;

        if (k == 1)
        {
            cout << n << "\n";
        }
        else
        {
            ll step = 0;
            while (n > 0)
            {
                step += (n % k);
                n /= k;
            }

            cout << step << "\n";
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