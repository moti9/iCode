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
        int xor_a = 0;
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            xor_a ^= arr[i];
        }
        // cout << "xor_a : " << xor_a << "\n";

        if (xor_a == 0)
            cout << 0 << "\n";
        else
        {
            if (n & 1)
            {
                cout << xor_a << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }

        // int xor_b = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     xor_b ^= (arr[i] ^ xor_a);
        // }
        // // cout << "xor_b : " << xor_b << "\n";
        // if (xor_b == 0)
        //     cout << xor_a << "\n";
        // else
        //     cout << -1 << "\n";
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