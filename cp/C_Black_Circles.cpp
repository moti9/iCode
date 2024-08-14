#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll dist(ll x1, ll y1, ll x2, ll y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

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
        vector<ll> x(n), y(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        ll xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;

        bool flag = false;
        ll dst = dist(xs, ys, xt, yt);
        for (int i = 0; i < n; i++)
        {
            ll curr_dst = dist(xt, yt, x[i], y[i]);
            if (curr_dst <= dst)
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}