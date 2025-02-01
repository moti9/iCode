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
        int n, k;
        cin >> n >> k;
        vector<int> coins(n);
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        sort(coins.rbegin(), coins.rend());
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + coins[i] <= k)
                sum += coins[i];
            else
                break;
        }
        cout << k - sum << "\n";
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