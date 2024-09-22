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
        ll n, k;
        cin >> n >> k;

        // if (n == k)
        // {
        //     if (n == 1)
        //         cout << "NO\n";
        //     else
        //         cout << ((n & 1) ? "YES" : "NO") << "\n";
        // }
        // else
        // {
        int start = n - k + 1;
        int end = n;

        int odd_nums = 0;
        if ((start & 1) || (end & 1))
        {
            odd_nums = (end - start) / 2 + 1;
        }
        else
        {
            odd_nums = (end - start) / 2;
        }

        cout << ((odd_nums & 1) ? "NO" : "YES") << "\n";
        // }
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