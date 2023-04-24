#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll findways(ll n)
{
    ll ans = 0;
    ll sz = cbrt(n);
    for (ll i = 2; i <= sz; i += 1)
    {
        ans += n / (1LL * i * i * i);
    }
    return ans;
}

void solvehere()
{
    ll m;
    cin >> m;
    ll low = 0, high = 1e16;
    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        if (findways(mid) < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (findways(low) == m)
    {
        cout << low;
        return;
    }
    cout << -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
