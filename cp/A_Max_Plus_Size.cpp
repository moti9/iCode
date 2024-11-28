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

        int maxi_odd = 0;
        int maxi_even = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (i & 1)
            {
                maxi_odd = max(maxi_odd, x);
            }
            else
            {
                maxi_even = max(maxi_even, x);
            }
        }
        cout << max(maxi_odd + n / 2, maxi_even + (n + 1) / 2) << "\n";
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