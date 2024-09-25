#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll _gcd = gcd(a, b);
    return (a * b) / _gcd;
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

        if (n % 2 == 0 || n % k == 0)
        {
            cout << "YES\n";
        }
        else
        {
            if (n & 1)
            {
                if (k & 1 && n - k > 1)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
            else
            {
                if (k & 1 || n - k < 2)
                {
                    cout << "NO\n";
                }
                else
                {
                    cout << "YES\n";
                }
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