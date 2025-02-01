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

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool won = false;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            bool all_non_div = true;

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (abs(arr[i] - arr[j]) % k == 0)
                {
                    all_non_div = false;
                    break;
                }
            }
            if (all_non_div)
            {
                won = true;
                index = i + 1;
                break;
            }
        }
        if (won)
        {
            cout << "YES\n";
            cout << index << "\n";
        }
        else
        {
            cout << "NO\n";
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