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
        vector<int> notes(n);
        for (int i = 0; i < n; i++)
        {
            cin >> notes[i];
        }

        bool is_perfect = true;
        for (int i = 0; i < n - 1; i++)
        {
            int diff = abs(notes[i] - notes[i + 1]);
            if (diff != 5 && diff != 7)
            {
                is_perfect = false;
                break;
            }
        }
        cout << ((is_perfect) ? "YES\n" : "NO\n");
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