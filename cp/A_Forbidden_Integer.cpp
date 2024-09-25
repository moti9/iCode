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
        int n, k, x;
        cin >> n >> k >> x;

        if (x == 1)
        {
            if (k == 1)
                cout << "NO\n";
            else if (k == 2)
            {
                if (n & 1)
                {
                    cout << "NO\n";
                }
                else
                {
                    cout << "YES\n";
                    cout << n / 2 << "\n";
                    for (int i = 0; i < n / 2; i++)
                    {
                        cout << 2 << " ";
                    }
                    cout << "\n";
                }
            }
            else
            {
                cout << "YES\n";
                cout << n / 2 << "\n";
                for (int i = 0; i < n / 2 - 1; i++)
                {
                    cout << 2 << " ";
                }
                if (n & 1)
                    cout << 3 << " ";
                else
                    cout << 2 << " ";
                cout << "\n";
            }
        }
        else
        {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++)
                cout << 1 << " ";
            cout << "\n";
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