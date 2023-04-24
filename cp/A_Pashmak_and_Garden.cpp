#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 != x2 && y1 != y2 && abs(x1 - x2) != abs(y1 - y2))
    {
        cout << -1;
    }
    else if (x1 == x2)
    {
        int dist = abs(y1 - y2);
        int x3, y3, x4, y4;
        y3 = y1;
        y4 = y2;
        x3 = x1 + dist;
        x4 = x2 + dist;
        cout << x3 << " " << y3 << " " << x4 << " " << y4;
    }
    else if (y1 == y2)
    {
        int dist = abs(x1 - x2);
        int x3, y3, x4, y4;
        x3 = x1;
        x4 = x2;
        y3 = y1 + dist;
        y4 = y2 + dist;
        cout << x3 << " " << y3 << " " << x4 << " " << y4;
    }
    else
    {
        int x3, y3, x4, y4;
        x3 = x1;
        x4 = x2;
        y3 = y2;
        y4 = y1;
        cout << x3 << " " << y3 << " " << x4 << " " << y4;
    }
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
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
