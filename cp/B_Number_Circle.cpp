#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    ll n;
    cin >> n;
    vector<ll> num(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    if (num[n - 1] >= num[n - 2] + num[n - 3])
    {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for (ll i = n % 2; i < n; i += 2)
    {
        cout << num[i] << " ";
    }
    for (ll i = n - 1; i >= 0; i -= 2)
    {
        cout << num[i] << " ";
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
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
