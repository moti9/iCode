#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    ll w, h;
    cin >> w >> h;
    ll basex = 0, basey = 0;
    for (int i = 0; i < 4; i++)
    {
        ll k;
        cin >> k;
        vector<ll> point(k);
        for (int j = 0; j < k; j++)
        {
            cin >> point[j];
        }
        if (i < 2)
        {
            basex = max(basex, point[k - 1] - point[0]);
        }
        else
        {
            basey = max(basey, point[k - 1] - point[0]);
        }
    }
    ll arx = basex * h;
    ll ary = basey * w;
    cout << max(arx, ary) << "\n";
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
