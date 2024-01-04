#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool check(vector<ll> &a, ll n, ll h, ll k)
{
    ll sum = 0;
    for (ll i = 1; i < n; i++)
    {
        sum += min(a[i] - a[i - 1], k);
    }
    if (sum + k >= h)
    {
        return 1;
    }
    return 0;
}

void solvehere()
{
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    ll low = 0, high = 1e18;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(a, n, h, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
