#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int a, b, c;
    cin >> a >> b >> c;
    int first = -1, second = -1;
    if (a < c)
    {
        first = 1;
    }

    if ((c / b) >= a)
    {
        cout << first << " " << second << "\n";
        return;
    }
    cout << first << " " << b << "\n";
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
