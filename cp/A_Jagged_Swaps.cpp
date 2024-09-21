#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool can_sort(int n, vector<int> arr)
{
    bool req_ops = false;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            req_ops = true;
            swap(arr[i], arr[i + 1]);
        }
    }
    if (is_sorted(arr.begin(), arr.end()))
        return true;
    if (req_ops)
    {
        if (can_sort(n, arr))
            return true;
        return false;
    }
    return false;
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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (can_sort(n, arr))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
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