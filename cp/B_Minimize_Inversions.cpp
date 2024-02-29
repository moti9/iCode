#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool comp(vector<ll> &a, vector<ll> &b)
{
    ll first = (ll)a[0] + (ll)b[0];
    ll second = (ll)a[1] + (ll)b[1];
    return (first <= second) && (a[0] < a[1]) && (b[0] < b[1]);
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
        ll n;
        cin >> n;
        vector<vector<ll>> ab(n, vector<ll>(2));
        for (ll i = 0; i < n; i++)
        {
            cin >> ab[i][0];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> ab[i][1];
        }

        sort(ab.begin(), ab.end());

        for (ll i = 0; i < n; i++)
        {
            cout << ab[i][0] << " ";
        }
        cout << "\n";
        for (ll i = 0; i < n; i++)
        {
            cout << ab[i][1] << " ";
        }
        cout << "\n";
    }
    return 0;
}