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

        string cells;
        cin >> cells;

        int cell_count[3] = {0};
        bool not_empty = true;
        for (int i = 0; i < n; i++)
        {
            if (cells[i] == '.')
            {
                not_empty = false;
                int st = i;
                while (i + 1 < n && cells[i + 1] == '.')
                    i++;
                int len = i - st + 1;
                if (len >= 3)
                {
                    cell_count[2]++;
                }
                else if (len == 2)
                {
                    cell_count[1]++;
                }
                else if (len == 1)
                {
                    cell_count[0]++;
                }
            }
        }

        if (not_empty)
        {
            cout << 0;
        }
        else
        {
            if (cell_count[2] > 0)
                cout << 2;
            else
            {
                cout << cell_count[0] + cell_count[1] * 2;
            }
        }
        cout << "\n";
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