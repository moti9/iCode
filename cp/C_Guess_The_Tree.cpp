#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

inline int query(int a, int b)
{
    cout << "? " << a + 1 << " " << b + 1 << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        vector<int> parent(n, -1);
        int remaining_queries = 15 * n;

        for (int i = 1; i < n; i++)
        {
            int a = i;
            int b = 0;

            while (remaining_queries > 0)
            {
                int x = query(a, b);
                remaining_queries--;
                if (x == a)
                    break;
                b = x;
            }
            parent[a] = b;
        }
        cout << "! ";
        for (int i = 1; i < n; i++)
        {
            cout << parent[i] + 1 << " " << i + 1 << " ";
        }
        cout << "\n";
        cout.flush();
    }
    return 0;
}

/*
  ___  ___     _______    ____________   _
 |   \/   |   /  ___  \  |_____  _____| | |
 | |\  /| |  |  /   \  |       | |      | |
 | | \/ | |  |  |   |  |       | |      | |
 | |    | |  |  \___/  |       | |      | |
 |_|    |_|   \_______/        |_|      |_|

*/