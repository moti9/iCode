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
        int n;
        cin >> n;

        bool all_px = true;
        bool all_nx = true;
        bool all_py = true;
        bool all_ny = true;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;

            if (x < 0)
            {
                all_px = false;
            }
            if (x > 0)
            {
                all_nx = false;
            }
            if (y < 0)
            {
                all_py = false;
            }
            if (y > 0)
            {
                all_ny = false;
            }
        }

        if (all_px || all_nx || all_py || all_ny)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}