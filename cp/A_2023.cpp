#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n, k;
        cin >> n >> k;

        ll mult = 1;
        for (int i = 0; i < n; i++)
        {
            ll b;
            cin >> b;
            mult *= b;
        }
        if (mult > 2023)
        {
            cout << "NO\n";
        }
        else
        {
            if (2023 % mult == 0)
            {
                cout << "YES\n";
                cout << 2023 / mult << " ";
                for (int i = 0; i < k - 1; i++)
                {
                    cout << 1 << " ";
                }
                cout << "\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}