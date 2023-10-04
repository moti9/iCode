#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class solution
{
public:
    solution()
    {
        ll x, y, z;
        cin >> x >> y >> z;

        if (x == y && y == z)
        {
            cout << "YES" << endl;
            cout << x << " " << y << " " << z << endl;
        }
        else if (x == y && x > z)
        {
            cout << "YES" << endl;
            cout << x << " " << z << " " << z << endl;
        }
        else if (x == z && x > y)
        {
            cout << "YES" << endl;
            cout << x << " " << y << " " << y << endl;
        }
        else if (y == z && y > x)
        {
            cout << "YES" << endl;
            cout << y << " " << x << " " << x << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solution moti;
    }
    return 0;
}
