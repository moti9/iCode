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
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int color;
            cin >> color;
            mp[color]++;
        }

        int cnt1 = 0, cntn = 0;
        for (auto x : mp)
        {
            if (x.second == 1)
                cnt1 += 1;
            else
                cntn += 1;
        }
        cout << (((cnt1 + 1) / 2) * 2) + cntn << "\n";
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