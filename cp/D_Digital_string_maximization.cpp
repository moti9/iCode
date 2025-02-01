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
        for (int i = 0; i < n; i++)
        {
            int ind = i;
            int ch = s[i] - '0';
            for (int j = 1; j < 10 && i + j < n; j++)
            {
                int curr = (s[i + j] - '0') - j;
                if (curr > ch && curr)
                {
                    ind = i + j;
                    ch = curr;
                }
            }
            if (i != ind)
            {
                while (i < ind)
                {
                    s[ind] = s[ind - 1];
                    ind--;
                }
                s[i] = ch + '0';
            }
        }
        cout << s << "\n";
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