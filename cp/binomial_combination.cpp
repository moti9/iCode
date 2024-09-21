#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll calc_combination(ll n, ll k)
{
    ll res = 1;
    for (ll i = n - k + 1; i <= n; i++)
    {
        res *= i;
    }
    for (ll i = 2; i <= k; i++)
    {
        res /= i;
    }
    return res;
}

ll calc_combination_improved(ll n, ll k)
{
    double res = 1;
    for (ll i = 1; i <= k; i++)
    {
        res = res * (double)((n - k + i) / i);
    }
    return (ll)(res + 0.01);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
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