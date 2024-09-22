#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool check(ll sum, ll x, ll n, vector<ll> &wt)
{
    ll unhappy = 0;
    wt[n - 1] = wt[n - 1] + x;
    double avg = (double)(sum + x) / (double)n;
    for (ll num : wt)
    {
        if ((double)num < (double)(avg / 2.0))
            unhappy++;
    }
    wt[n - 1] = wt[n - 1] - x;

    return unhappy > n / 2;
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
        ll n;
        cin >> n;

        vector<ll> wt(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
            sum += wt[i];
        }
        sort(wt.begin(), wt.end());

        ll left = 0, right = 1e16;
        ll ans = 1e17;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;

            if (check(sum, mid, n, wt))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (ans == 1e17)
        {
            cout << -1 << "\n";
        }
        else
        {
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