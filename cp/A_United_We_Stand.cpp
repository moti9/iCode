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
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            st.insert(arr[i]);
        }

        if (n == 1 || st.size() < 2)
            cout << -1 << "\n";
        else
        {
            sort(arr.begin(), arr.end());
            vector<int> b, c;
            c.push_back(arr.back());
            for (int i = n - 2; i >= 0; i--)
            {
                if (c.back() == arr[i])
                {
                    c.push_back(arr[i]);
                }
                else
                {
                    b.push_back(arr[i]);
                }
            }
            cout << b.size() << " " << c.size() << "\n";
            for (auto &x : b)
            {
                cout << x << " ";
            }
            cout << "\n";
            for (auto &x : c)
                cout << x << " ";
            cout << "\n";
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