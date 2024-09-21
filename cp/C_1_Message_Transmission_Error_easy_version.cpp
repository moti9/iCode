#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        string s;
        cin >> s;

        int n = s.length();
        for (int len = (n + 2) / 2; len < n; len++)
        {
            string left = s.substr(0, len);
            string right = s.substr(n - len, len);
            if (left == right)
            {
                cout << "YES\n"
                     << left << "\n";
                return 0;
            }
        }
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