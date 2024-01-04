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
    // cin>>ttt;
    while (ttt--)
    {
        ll n, m, k;
        cin >> n >> m >> k;

        ll low = 1, high = n * m;

        while (low < high)
        {
            ll mid = low + (high - low) / 2;
            ll count = 0;

            for (ll i = 1; i <= n; i++)
            {
                count += min(mid / i, m);
            }

            if (count < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        cout << low << "\n";
    }
    return 0;
}
