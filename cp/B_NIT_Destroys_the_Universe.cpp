#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl "\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    bool all_zero = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            all_zero = false;
            break;
        }
    }
    
    if (all_zero)
    {
        cout << 0 << endl;
        return;
    }
    
    int left = -1, right = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            if (left == -1) left = i;
            right = i;
        }
    }
    
    bool contiguous = true;
    for (int i = left; i <= right; i++)
    {
        if (arr[i] == 0)
        {
            contiguous = false;
            break;
        }
    }
    
    if (contiguous)
        cout << 1 << endl;
    else
        cout << 2 << endl;
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// #include <bits/stdc++.h>
// #include<iostream>
// using namespace std;
// #define ll long long
// #define mod 1000000007

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     ll ttt = 1;
//     cin >> ttt;
//     while (ttt--)
//     {
//         int n;
//         cin >> n;
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         int cnt = 0;
//         for (int i = 0; i < n;)
//         {
//             if (arr[i] != 0)
//             {
//                 cnt += 1;
//                 while (i < n && arr[i] != 0)
//                     i += 1;
//             }
//             else
//             {
//                 i += 1;
//             }
//         }
//         cout << cnt << "\n";
//     }
//     return 0;
// }
// /*
//  ___  ___     _______    ____________    _
// |   \/   |   /  ___  \  |_____  _____|  | |
// | |\  /| |  |  /   \  |       | |       | |
// | | \/ | |  |  |   |  |       | |       | |
// | |    | |  |  \___/  |       | |       | |
// |_|    |_|   \_______/        |_|       |_|

// */