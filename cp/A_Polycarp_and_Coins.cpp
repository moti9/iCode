#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define rep(i, a, b) for (int i = a; i < b; i++)
#define repi(i, a, b) for (int i = b - 1; i >= a; i--)
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll c1 = 0, c2 = 0;
        ll n;
        cin >> n;
        if (n % 3 == 0)
        {
            c1 = n / 3;
            c2 = c1;
        }
        else if (n % 3 == 1)
        {
            c2 = n / 3;
            c1 = c2 + 1;
        }
        else if (n % 3 == 2)
        {
            c1 = n / 3;
            c2 = c1 + 1;
        }

        cout << c1 << " " << c2 << "\n";
    }

    return 0;
}