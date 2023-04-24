#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    ll n, i;
    cin >> n;
    vector<ll> v1(n), v2(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    vector<ll> v;
    ll c, mi = INT_MAX;
    for (i = 0; i < n; i++)
    {
        c = v1[0] + v2[i];
        c = c % n;
        mi = min(mi, c);
    }
    for (i = 0; i < n; i++)
    {
        c = v1[0] + v2[i];
        c = c % n;
        if (c == mi)
        {
            v.push_back(i);
        }
    }
    if (v.size() == 1)
    {
        ll a = v[0];
        ll p = 0;
        for (ll j = a; j < n; j++, p++)
        {
            cout << (v1[p] + v2[j]) % n << " ";
        }
        for (ll j = 0; j < a; j++, p++)
        {
            cout << (v1[p] + v2[j]) % n << " ";
        }
    }
    else
    {
        vector<ll> a1;
        vector<ll> a2;
        ll a = v[0], p = 0;

        for (ll j = a; j < n; j++, p++)
        {
            a1.push_back((v1[p] + v2[j]) % n);
        }

        for (ll j = 0; j < a; j++, p++)
        {
            a1.push_back((v1[p] + v2[j]) % n);
        }
        a = v[1];
        p = 0;

        for (ll j = a; j < n; j++, p++)
        {

            a2.push_back((v1[p] + v2[j]) % n);
        }
        for (ll j = 0; j < a; j++, p++)
        {

            a2.push_back((v1[p] + v2[j]) % n);
        }
        if (a1 < a2)
        {
            for (i = 0; i < n; i++)
            {
                cout << a1[i] << " ";
            }
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                cout << a2[i] << " ";
            }
        }
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif

    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
