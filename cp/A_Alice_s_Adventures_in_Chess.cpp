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
        int n, a, b;
        cin >> n >> a >> b;
        string moves;
        cin >> moves;

        int nom = 1e3;
        int ind = 0;
        int x = 0, y = 0;
        bool not_reached = true;
        while (nom--)
        {
            if (moves[ind] == 'N')
                y += 1;
            else if (moves[ind] == 'S')
                y -= 1;
            else if (moves[ind] == 'E')
                x += 1;
            else if (moves[ind] == 'W')
                x -= 1;

            if (x == a && y == b)
            {
                cout << "YES\n";
                not_reached = false;
                break;
            }
            ind += 1;
            if (ind >= n)
                ind = 0;
        }
        if (not_reached)
            cout << "NO\n";
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