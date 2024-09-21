#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int solve(int i, int j, vector<int> &arr)
{
    if (i >= j)
    {
        return 0;
    }
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
        int n;
        cin >> n;
        vector<int> arr(n);
        ll total_sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            total_sum += (ll)arr[i];
        }

        if (n == 2)
        {
            cout << arr[1] - arr[0] << "\n";
        }
        else
        {
            ll second = arr[n - 2];
            ll last = arr[n - 1];
            ll rem = total_sum - last - second;

            cout << last - (second - rem) << "\n";
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