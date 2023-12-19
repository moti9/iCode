#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool canBakeCookies(ll cur, vector<ll> &ingredients, vector<ll> &available, ll k)
{
    for (ll i = 0; i < ingredients.size(); ++i)
    {
        ll needed = (ingredients[i] * cur) - available[i];
        if (needed > 0)
        {
            k -= needed;
        }
        if (k < 0)
        {
            return false;
        }
        // cout << k << "-";
    }

    return k >= 0;
}

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> ingredients(n);
    vector<ll> available(n);

    for (ll i = 0; i < n; ++i)
    {
        cin >> ingredients[i];
    }

    for (ll i = 0; i < n; ++i)
    {
        cin >> available[i];
    }

    ll low = 0, high = 2e9;
    ll ans = 0;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;

        if (canBakeCookies(mid, ingredients, available, k))
        {
            low = mid + 1;
            ans = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
