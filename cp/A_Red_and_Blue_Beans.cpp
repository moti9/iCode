#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class solution
{
public:
    solution()
    {
        ll r, b, d;
        cin >> r >> b >> d;

        ll minBeans = min(r, b);
        ll maxBeans = max(r, b);

        if (minBeans * (d + 1) >= maxBeans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
};

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
        solution moti;
    }
    return 0;
}
