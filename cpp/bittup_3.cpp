#include <bits/stdc++.h>
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define md 1000000007
#define ll long long int
using namespace std;

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll x = 0, y = 0;
        x = pow(2, n) - 1;
        y = pow(x % md, m);
        cout << y % md << endl;
    }

    return 0;
}
