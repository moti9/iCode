#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    ll n, k;
    cin >> n >> k;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> rpq;
    priority_queue<pair<ll, ll>> lpq;
    vector<ll> ht(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ht[i];
    }

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x < 0)
        {
            lpq.push({x, ht[i]});
        }
        else
        {
            rpq.push({x, ht[i]});
        }
    }

    // while (!lpq.empty())
    // {
    //     cout << lpq.top().first << " " << lpq.top().second << "\n";
    //     lpq.pop();
    // }
    // cout << "--\n";
    // while (!rpq.empty())
    // {
    //     cout << rpq.top().first << " " << rpq.top().second << "\n";
    //     rpq.pop();
    // }
    // cout << "done--\n";

    ll left = 0, right = 0, gun = 0;
    while (lpq.size() > 0 || rpq.size() > 0)
    {
        gun += k;
        // for left side
        if (lpq.size() > 0)
        {
            ll pl = lpq.top().first;
            if (pl >= left)
            {
                cout << "NO\n";
                return;
            }
            ll lh = lpq.top().second;
            if (left - pl == 1)
            {
                if (gun < lh)
                {
                    cout << "NO\n";
                    return;
                }
                gun -= lh;
                lpq.pop();
            }
        }
        // for right side
        if (rpq.size() > 0)
        {
            ll pr = rpq.top().first;
            if (pr <= right)
            {
                cout << "NO\n";
                return;
            }
            ll rh = rpq.top().second;
            if (pr - right == 1)
            {
                if (gun < rh)
                {
                    cout << "NO\n";
                    return;
                }
                gun -= rh;
                rpq.pop();
            }
        }
        left -= 1;
        right += 1;
    }

    if (gun < 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
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
        solve();
    }
    return 0;
}