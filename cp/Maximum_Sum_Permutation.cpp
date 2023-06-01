#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void countFrequency(ll l, ll r, unordered_map<ll, ll> &frequencyMap)
{
    if (l == r)
    {
        frequencyMap[l]++;
        return;
    }
    while (l < r)
    {
        frequencyMap[l]++;
        frequencyMap[r]++;
        l += 1;
        r -= 1;
    }
    if (l == r)
        frequencyMap[l]++;
    return;
}

void solvehere()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<ll, ll> freq;
    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        countFrequency(l - 1, r - 1, freq);
    }
    vector<pair<ll, ll>> ip;
    for (auto fr : freq)
    {
        ip.push_back({fr.second, fr.first});
    }
    sort(ip.rbegin(), ip.rend());
    sort(arr.rbegin(), arr.rend());
    ll sum = 0;
    vector<ll> ans(n);
    ll j = 0;
    for (auto i : ip)
    {
        ll fr = i.first;
        ll index = i.second;
        ans[index] = arr[j];
        sum += fr * ans[index];
        j += 1;
    }
    cout << sum << "\n";
    for (auto a : ans)
        cout << a << " ";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
