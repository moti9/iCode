#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll one = 0, zero = 0;
    ll ans = 1;
    ll ct = 1;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zero += 1;
        }
        else
        {
            one += 1;
        }
        if (s[i] == s[i + 1])
        {
            ct += 1;
        }
        else
        {
            ans = max(ans, ct * ct);
            ct = 1;
        }
    }
    ans = max(ans, one * zero);
    cout << ans << "\n";
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
