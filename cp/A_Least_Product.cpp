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
        int n;
        cin >> n;
        ll mult = 1LL;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            mult *= (ll)x;
        }
        if (mult <= 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1 << "\n";
            cout << 1 << " " << 0 << "\n";
        }
    }
    return 0;
}