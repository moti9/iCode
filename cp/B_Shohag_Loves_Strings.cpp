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
        int n = s.length();

        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {
                if (s[i] == s[i + 1])
                {
                    cout << s.substr(i, 2) << "\n";
                    found = true;
                    break;
                }
                if (i + 2 < n)
                {
                    if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i + 2] != s[i])
                    {
                        cout << s.substr(i, 3) << "\n";
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found)
            cout << "-1\n";
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