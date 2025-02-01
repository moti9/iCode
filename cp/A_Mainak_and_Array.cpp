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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, arr[(i - 1 + n) % n] - arr[i]);
        }
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, arr[i] - arr[0]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, arr[n - 1] - arr[i]);
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