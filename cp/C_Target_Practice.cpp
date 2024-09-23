#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<vector<int>> mat(10, vector<int>(10, 1));

void set_point()
{
    for (int i = 1; i < 5; i++)
    {
        // upper row
        // lower row
        for (int j = i; j < 10 - i; j++)
        {
            mat[i][j] = i + 1;
            mat[10 - i - 1][j] = i + 1;
        }
    }

    for (int j = 1; j < 5; j++)
    {
        for (int i = j; i < 10 - j; i++)
        {
            mat[i][j] = j + 1;
            mat[i][10 - j - 1] = j + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    set_point();
    while (ttt--)
    {
        vector<string> arrow(10);
        for (int i = 0; i < 10; i++)
        {
            cin >> arrow[i];
        }
        int points = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                (arrow[i][j] == 'X') ? points += mat[i][j] : 0;
            }
        }
        cout << points << "\n";
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