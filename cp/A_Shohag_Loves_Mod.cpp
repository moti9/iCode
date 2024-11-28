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
        vector<int> ans;
        unordered_map<int, int> ump;
        ans.push_back(1);
        ump[0]++;
        for (int i = 2; i <= 100 && ans.size() < n; i++)
        {
            int ci = ans.size() + 1;
            if (ump[i % ci] == 0)
            {
                ans.push_back(i);
                ump[i % ci]++;
            }
        }
        for (auto &a : ans)
            cout << a << " ";
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