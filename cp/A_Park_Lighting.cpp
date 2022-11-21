#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n, m;
    cin >> n >> m;
    if (n % 2 == 0)
    {
        cout << (m * (n / 2)) << "\n";
    }
    else
    {
        if (m % 2 == 0)
        {
            cout << (n * (m / 2)) << "\n";
        }
        else
        {
            int total = (n * (m / 2)) + (n + 1) / 2;
            cout << total << "\n";
        }
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
