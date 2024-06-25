#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int x, y;
        cin >> x >> y;
        if (x == 0)
        {
            cout << (y + 1) / 2 << "\n";
            continue;
        }
        if (y == 0)
        {
            cout << (x + 14) / 15 << "\n";
            continue;
        }
        int ans = 0;
        if (y % 2 == 0)
        {
            ans += y / 2;
            x -= (7 * ans);
        }
        else
        {
            ans += (y + 1) / 2;
            x -= (7 * ans) + 4;
        }
        if (x > 0)
        {
            ans += (x + 14) / 15;
        }
        cout << ans << "\n";
    }

    return 0;
}