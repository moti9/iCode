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
        int n, m;
        cin >> n >> m;
        int cnt = 0;
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if ((len >= 0) && ((len + s.length()) <= m))
            {
                cnt += 1;
                len += s.length();
            }
            else
            {
                len = -1;
            }
        }
        cout << cnt << "\n";
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