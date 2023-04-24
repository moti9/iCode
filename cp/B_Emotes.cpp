#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> card(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> card[i];
    }
    sort(card.begin(), card.end());
    ll temp = m / (k + 1);
    ll rem = m % (k + 1);
    ll first = ((temp * k) + rem) * card[n - 1];
    ll second = temp * card[n - 2];
    cout << first + second;
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
