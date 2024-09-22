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
        int n, k;
        cin >> n >> k;

        // int cnt_zero = 0;
        int gold = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x >= k)
            {
                gold += x;
            }
            else if (x == 0)
            {
                // cnt_zero++;
                if (gold > 0)
                {
                    gold--;
                    // cnt_zero--;
                    ans++;
                }
            }
        }
        // if (cnt_zero > 0)
        // {
        //     ans += min(cnt_zero, gold);
        // }
        cout << ans << "\n";
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