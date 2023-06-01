#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    ll l, r;
    cin >> l >> r;
    ll count = 0;

    for (ll a = l; a <= r; ++a)
    {
        for (ll b = a; b <= r; ++b)
        {
            if ((a ^ b) == (a + b) && (a + b))
            {
                count++;
            }
        }
    }
    cout << count << "\n";
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
