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
        string s;
        cin >> s;
        int c0 = count(s.begin(), s.end(), '0');
        int c1 = count(s.begin(), s.end(), '1');
        bool turn = !(min(c0, c1) & 1);

        // while (true)
        // {
        //     auto fa = s.find("01");
        //     auto fb = s.find("10");
        //     if (fa != string::npos)
        //     {
        //         int idx = fa;
        //         s.erase(idx, 2);
        //     }
        //     else if (fb != string::npos)
        //     {
        //         int idx = fb;
        //         s.erase(idx, 2);
        //     }
        //     else
        //     {
        //         break;
        //     }
        //     turn = !turn;
        // }
        cout << ((turn) ? "NET" : "DA") << "\n";
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