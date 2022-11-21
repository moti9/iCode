#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    ll x, y, z;
    cin >> x >> y >> z;
    // ll buy = (x / z) + (y / z);
    ll buy = (x + y) / z;
    // cout << buy << "\n";
    x %= z;
    y %= z;
    // cout << x << "\n";
    // cout << y << "\n";
    ll deb = 0;
    if (x + y >= z)
    {
        // buy += ((x + y) / z);
        deb = z - max(x, y);
    }
    cout << buy << " " << deb;
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
