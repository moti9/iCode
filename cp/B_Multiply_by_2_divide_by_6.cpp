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

        int cnt2 = 0, cnt3 = 0;
        while (n % 2 == 0)
        {
            cnt2 += 1;
            n /= 2;
        }
        while (n % 3 == 0)
        {
            cnt3 += 1;
            n /= 3;
        }

        if (n != 1)
        {
            cout << -1 << "\n";
        }
        else
        {
            if (cnt2 <= cnt3)
            {
                cout << (cnt3 - cnt2) + cnt3 << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
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