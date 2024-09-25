#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        int prev = 0, mn_diff = 1e9 + 2;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (prev != 0)
            {
                mn_diff = min(mn_diff, x - prev);
            }
            prev = x;
        }
        cout << ((mn_diff < 0) ? 0 : ((mn_diff & 1) ? (mn_diff + 1) / 2 : (mn_diff / 2 + 1))) << "\n";
    }
    return 0;
}
/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/