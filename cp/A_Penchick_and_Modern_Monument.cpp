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
        int cnt = 0, ccnt = 0, cnum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (cnum == x)
            {
                ccnt += 1;
            }
            else
            {
                ccnt = 1;
                cnum = x;
            }
            cnt = max(cnt, ccnt);
        }
        cout << n - cnt << "\n";
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