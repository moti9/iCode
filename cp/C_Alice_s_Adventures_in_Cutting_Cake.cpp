#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<ll> compute_pre_suff(vector<ll> &ttness, ll n, ll v)
{
    vector<ll> pref(n + 1);
    ll j = 0;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        while (j < n && sum < v)
        {
            sum += ttness[j];
            j += 1;
            pref[j] = max(pref[j], pref[j - 1]);
        }
        if (sum >= v)
        {
            pref[j] = 1 + pref[i];
        }
        sum -= ttness[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        pref[i] = max(pref[i], pref[i - 1]);
    }
    return pref;
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
        ll n, m, v;
        cin >> n >> m >> v;

        vector<ll> ttness(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> ttness[i];
        }

        vector<ll> pref = compute_pre_suff(ttness, n, v);
        reverse(ttness.begin(), ttness.end());
        vector<ll> suff = compute_pre_suff(ttness, n, v);
        reverse(ttness.begin(), ttness.end());
        reverse(suff.begin(), suff.end());

        if (pref[n] < m)
        {
            cout << "-1\n";
            continue;
        }

        vector<ll> psum(n + 1);
        for (ll i = 0; i < n; i++)
            psum[i + 1] = psum[i] + ttness[i];

        ll ans = 0;
        ll j = 0;
        for (ll i = 0; i < n; i++)
        {
            while (j < n && pref[i] + suff[j + 1] >= m)
                j += 1;
            if (pref[i] + suff[j] >= m)
            {
                ans = max(ans, (psum[j] - psum[i]));
            }
        }
        cout << ans << "\n";
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