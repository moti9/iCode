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
        int mini = 101, maxi = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mini = min(arr[i], mini);
            maxi = max(arr[i], maxi);
        }

        if (maxi != mini)
        {
            sort(arr.begin(), arr.end());
            cout << "YES\n";
            swap(arr[0], arr[1]);
            swap(arr[n - 1], arr[0]);
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