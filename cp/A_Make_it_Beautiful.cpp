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
        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            ump[arr[i]]++;
        }
        sort(arr.begin(), arr.end());

        int skip = (n + 1) / 2;
        for (int i = 0; i < n / 2; i++)
        {
            swap(arr[i], arr[(n + 1) / 2 + i]);
        }
        // cout << "--S\n";
        // for (auto &x : arr)
        //     cout << x << " ";
        // cout << "\n";
        // cout << "--E\n";

        int sum = arr[0];
        ump[sum]--;
        bool possible = true;
        for (int i = 1; i < n; i++)
        {
            if (ump[sum] > 0)
            {
                possible = false;
                break;
            }
            sum += arr[i];
        }
        if (possible)
        {
            cout << "YES\n";
            for (auto &x : arr)
                cout << x << " ";
            cout << "\n";
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