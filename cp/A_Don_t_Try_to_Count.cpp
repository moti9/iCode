#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

string temp = "";

bool check(int ops, int n, int m, string x, string &s)
{
    temp = x;
    for (int i = 1; i <= ops; i++)
    {
        temp += temp;
    }
    auto found = temp.find(s);
    temp = "";
    return found != string::npos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x;
        cin >> s;

        int left = 0, right = 5;
        int ans = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (check(mid, n, m, x, s))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << ans << "\n";
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