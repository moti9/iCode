#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        ll x, y, k;
        cin >> x >> y >> k;

        while (k > 0 && x != 1)
        {
            ll rem = y - (x % y);
            rem = max(1LL, rem);
            rem = min(rem, k);
            x += rem;
            while (x % y == 0)
            {
                x /= y;
            }
            k -= rem;
        }
        cout << x + k % (y - 1) << "\n";
    }
    return 0;
}