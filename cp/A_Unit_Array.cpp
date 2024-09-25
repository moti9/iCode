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
        int cpo = 0, cno = 0;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            (num == 1) ? cpo += 1 : cno += 1;
        }
        if (cpo >= cno && (cno % 2) == 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            int ops = 0;
            while ((cpo < cno) || (cno & 1))
            {
                cno -= 1;
                cpo += 1;
                ops += 1;
            }

            cout << ops << "\n";
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
