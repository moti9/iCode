#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class solution
{
public:
    solution()
    {
        int n, m, k;
        cin >> n >> m >> k;

        int amax = 0, amin = 1e9 + 2;
        ll asum = 0;
        // vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            // cin >> a[i];
            asum += a;
            amax = max(amax, a);
            amin = min(amin, a);
        }

        int bmax = 0, bmin = 1e9 + 2;
        // ll bsum = 0;
        // vector<int> b(m);

        for (int i = 0; i < m; i++)
        {
            int b;
            cin >> b;
            // cin >> b[i];
            // bsum += b;
            bmax = max(bmax, b);
            bmin = min(bmin, b);
        }
        if (amin < bmax)
        {
            asum += (bmax - amin);
            bmin = min(bmin, amin);
            amax = max(amax, bmax);
        }
        if (k % 2 == 0)
        {
            asum += (bmin - amax);
        }
        cout << asum << "\n";
        // if (bmax > amax)
        // {
        //     if (k & 1)
        //     {
        //         ll ans = asum + bmax - amin;
        //         cout << ans << "\n";
        //     }
        //     else
        //     {
        //         cout << asum << "\n";
        //     }
        // }
        // else
        // {
        //     if (k & 1)
        //     {
        //         if (amin < bmax)
        //         {
        //             ll ans = asum + bmax - amin;
        //             cout << ans << "\n";
        //         }
        //         else
        //         {
        //             cout << asum << "\n";
        //         }
        //     }
        //     else
        //     {
        //         if (amin < bmax)
        //         {
        //             ll ans = asum + bmax - amin;
        //             bmin = min(bmin, amin);
        //             ans -= amax;
        //             ans += bmin;
        //             cout << ans << "\n";
        //         }
        //         else
        //         {
        //             ll ans = asum - amax + bmin;
        //             cout << ans << "\n";
        //         }
        //     }
        // }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLaINEUDGE
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
