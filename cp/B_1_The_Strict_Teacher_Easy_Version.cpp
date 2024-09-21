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
        int n, m, q;
        cin >> n >> m >> q;
        set<int> mt;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            mt.insert(x);
        }
        while (q--)
        {
            int x;
            cin >> x;

            if (m == 1)
            {
                int tt = *mt.begin();
                if (x == tt)
                {
                    cout << 0 << "\n";
                }
                else if (x < tt)
                {
                    cout << tt - 1 << "\n";
                }
                else
                {
                    cout << n - tt << "\n";
                }
            }
            else
            {

                auto lb = mt.lower_bound(x);
                auto ub = mt.upper_bound(x);

                if (ub == mt.end())
                {
                    if (lb == mt.end())
                    {
                        // cout << "a";
                        cout << n - *mt.rbegin() << "\n";
                    }
                    else
                    {
                        // cout << "b";
                        cout << 0 << "\n";
                    }
                }
                else
                {
                    if (*lb == x)
                    {
                        // cout << "c";
                        cout << 0 << "\n";
                    }
                    else
                    {
                        if (mt.begin() != lb)
                        {
                            // cout << "d";
                            int mid = *ub - *prev(lb);
                            cout << mid / 2 << "\n";
                        }
                        else
                        {
                            // cout << "e";
                            cout << *lb - 1 << "\n";
                        }
                    }
                }
            }
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