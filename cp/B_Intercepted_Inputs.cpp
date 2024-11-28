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
        int k;
        cin >> k;
        vector<int> arr(k);
        unordered_map<int, int> ump;
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
            ump[arr[i]]++;
        }

        int gs = k - 2;

        int x = -1, y = -1;

        for (int n = 1; n <= sqrt(gs); n++)
        {
            if (gs % n == 0)
            {
                int m = gs / n;
                if (ump[n] > 0 && ump[m] > 0 && (n * m) == gs)
                {
                    x = n;
                    y = m;
                    break;
                }
            }
        }

        cout << x << " " << y << "\n";
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