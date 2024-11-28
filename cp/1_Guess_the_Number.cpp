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
    // cin>>ttt;
    while (ttt--)
    {
        int left = 1, right = 1e6;
        int cnt = 0;
        int ans = -1;
        while (left <= right && cnt < 25)
        {
            cnt += 1;
            int mid = (left + right) / 2;
            cout << mid << "\n";
            cout << flush;

            string query;
            cin >> query;
            if (query == "<")
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
                ans = max(ans, mid);
            }
        }
        cout << "! " << ans << endl;
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