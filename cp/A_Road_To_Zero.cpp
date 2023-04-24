#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    // It'll work for negative value of x,y
    ll x, y;
    cin >> x >> y;
    ll a, b;
    cin >> a >> b;
    if (2 * a <= b || (x * y < 0))
    {
        ll ans = (abs(x) + abs(y)) * a;
        cout << ans << "\n";
    }
    else
    {
        ll mx = max(x, y);
        ll mn = min(x, y);
        ll ans = ((b - a) * abs(mn)) + a * (abs(mx));
        cout << ans << "\n";
    }
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
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
