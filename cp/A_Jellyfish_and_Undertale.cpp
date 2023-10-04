#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class solution
{
public:
    solution()
    {
        ll a, b, n;
        cin >> a >> b >> n;
        // vector<ll> x(n);
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> x[i];
        // }
        ll bomb = b;
        ll time = bomb - 1;
        bomb = 1;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            bomb = min(a, bomb + x);
            if (bomb > 1)
            {
                time += (bomb - 1);
                bomb = 1;
            }
        }
        time += bomb;
        cout << time << "\n";
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
