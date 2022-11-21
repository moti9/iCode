#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define rep(i, a, b) for (int i = a; i < b; i++)
#define setDig(n) setprecision(int n)
#define li long int
#define ll long long
#define lli long long int
#define uli unsigned long int
#define ull unsigned long long
#define M 1000000007
using namespace std;

int main()
{
    fastio();
    ll n, m, a;
    cin >> n >> m >> a;

    // if (n % a == 0 && m % a == 0)
    // {
    //     cout << (n * m) / (a * a);
    //     return 0;
    // }
    // if (n % a != 0 && m % a == 0)
    // {
    //     cout << ((n / a) + 1) * (m / a);
    //     return 0;
    // }
    // if (n % a == 0 && m % a != 0)
    // {
    //     cout << ((m / a) + 1) * (n / a);
    //     return 0;
    // }

    // if (n % a != 0 && m % a != 0)
    // {
    //     cout << ((n / a) + 1) * ((m / a) + 1);
    //     return 0;
    // }
    ll ans = ((n + a - 1) / a) * ((m + a - 1) / a);
    cout << ans;
}