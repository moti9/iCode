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
        int q;
        cin >> q;
        int n = s.length();
        for (int i = 0; i < q; i++)
        {
            int ind, val;
            cin >> ind >> val;
            if (n < 4)
            {
                cout << "NO\n";
            }
            else
            {
                bool in_range = false;
                char curr_val;
                if (ind < n)
                {
                    curr_val = s[ind];
                    s[ind] = val + '0';
                    in_range = true;
                }
                if (s.find("1100") != string::npos)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
                // if (in_range)
                // {
                //     s[ind] = curr_val;
                // }
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