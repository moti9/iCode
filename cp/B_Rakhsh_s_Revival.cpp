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
        int n, m, k;
        cin >> n >> m >> k;

        string s;
        cin >> s;

        int cnt = 0;
        for (int i = 0; i < n;)
        {
            if (s[i] == '0')
            {
                bool all_skipped = true;

                for (int j = 0; j < m - 1; j++)
                {
                    i++;
                    if (i >= n || s[i] != '0')
                    {
                        all_skipped = false;
                        break;
                    }
                }

                if (all_skipped)
                {
                    cnt++;

                    for (int j = 0; j < k; j++)
                    {
                        i++;
                        if (i >= n)
                            break;
                    }
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
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
