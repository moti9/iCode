#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int a, b, c;
    cin >> a >> b >> c;
    int mult = pow(10, c - 1);
    int ta = a - c;
    int tb = b - c;
    int x = 1, y = 0;
    for (int i = 0; i < ta; i++)
    {
        x = x * 10 + 1;
    }
    y = pow(10, tb);
    y *= 2;
    y *= mult;
    x *= mult;
    cout << x << " " << y << "\n";
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
