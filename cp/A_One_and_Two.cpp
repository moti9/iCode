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
        int cnt_2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            cnt_2 += (arr[i] == 2);
        }
        if (cnt_2 & 1)
        {
            cout << "-1\n";
        }
        else
        {
            int index = 0;
            int left = cnt_2 / 2;
            while (left > 0)
            {
                if (arr[index] == 2)
                    left -= 1;
                index++;
            }
            if (index == 0)
            {
                if (arr[index + 1] == 1)
                    index++;
            }
            cout << index << "\n";
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