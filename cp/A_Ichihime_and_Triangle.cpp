#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b > c)
    {
        cout << a << " " << b << " " << c << "\n";
        return;
    }
    if (a + c > d)
    {
        cout << a << " " << c << " " << d << "\n";
        return;
    }
    if (c + b > d)
    {
        cout << b << " " << c << " " << d << "\n";
        return;
    }
    cout << b << " " << c << " " << c << "\n";
    return;
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
