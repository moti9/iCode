#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
#define ll long long int
int main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ct = 0;
        for (ll i = 1; i <= 9; i++)
        {
            for (ll j = i; j <= n; j++)
            {
                ct++;
                j = (j * 10) + i;
            }
        }
        cout << ct << "\n";
    }

    return 0;
}