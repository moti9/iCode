#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void countP(vector<int> &p, int n, unordered_map<ll, ll> &mp)
{
    for (int i = 0; i < n; i++)
    {
        ll sum = p[i];
        mp[sum]++;
        for (int j = i + 1; j < n; j++)
        {
            sum += (ll)p[j];
            mp[sum]++;
        }
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
        int n;
        cin >> n;
        vector<int> per(n);
        for (int i = 0; i < n; i++)
        {
            cin >> per[i];
        }
        unordered_map<ll, ll> mp;
        countP(per, n, mp);
        for (int i = 1; i <= n; i++)
        {
            cout << mp[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}