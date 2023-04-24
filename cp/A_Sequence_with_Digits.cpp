#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll minMaxDig(ll n)
{
    ll mn = 9, mx = 1;
    while (n)
    {
        ll rem = n % 10;
        mn = min(mn, rem);
        mx = max(mx, rem);
        n /= 10;
    }
    return mx * mn;
}

void solvehere()
{
    ll a, k;
    cin >> a >> k;
    if (k == 1)
    {
        cout << a << "\n";
        return;
    }
    for (ll i = 2; i <= k; i++)
    {
        ll p = minMaxDig(a);
        if (p == 0)
        {
            break;
        }
        a = a + p;
    }
    cout << a << "\n";
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
