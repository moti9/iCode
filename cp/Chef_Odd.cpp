#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    if (n / k >= 2)
    {
        if (n % k == 0 && n / k == 2)
        {
            cout << "YES\n";
            return;
        }
        ll temp = n - 2 * (k - 1);
        ll sum = temp * (temp + 1) / 2;
        if (sum & 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else
    {
        cout << "NO\n";
    }
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
