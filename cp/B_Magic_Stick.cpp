#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int x, y;
    cin >> x >> y;
    if (x == y)
    {
        cout << "YES\n";
        return;
    }
    if (x == 1)
    {
        cout << "NO\n";
        return;
    }
    if (x < 4)
    {
        if (y < 4)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }
    cout << "YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
