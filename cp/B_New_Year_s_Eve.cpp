#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// ll computeXOR(ll n)
// {
//     if (n % 4 == 0)
//         return n;
//     else if (n % 4 == 1)
//         return 1;
//     else if (n % 4 == 2)
//         return n + 1;
//     else
//         return 0;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        ll n, k;
        cin >> n >> k;

        // ll ans = 0;
        // for (ll i = 1; i <= n; i++)
        // {
        //     ans ^= i;
        // }
        // cout << ans << "\n";
        if (k == 1)
        {
            cout << n << "\n";
        }
        else
        {
            long long p = 1;
            while ((p << 1) <= n)
            {
                p <<= 1;
            }
            cout << (1LL << (long long)(log2(p) + 1)) - 1 << "\n";
        }
    }
    return 0;
}