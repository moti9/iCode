#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    ll n;
    cin >> n;
    if (n <= 6)
    {
        cout << 15 << "\n";
    }
    else
    {
        if (n % 2 == 0)
        {
            cout << ((n * 2) + (n / 2)) << "\n";
        }
        else
        {
            n += 1;
            cout << ((n * 2) + (n / 2)) << "\n";
        }
    }
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
