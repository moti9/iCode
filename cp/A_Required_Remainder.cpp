#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int x, y, n;
    cin >> x >> y >> n;
    int rem = n % x;
    if (rem == y)
    {
        cout << n << "\n";
    }
    else if (rem > y)
    {
        cout << (n - rem + y) << "\n";
    }
    else
    {
        int temp = n - (n % x);
        cout << (temp - x + y) << "\n";
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
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
