#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << max({a, b, c}) - min({a, b, c}) << "\n";
    }
    return 0;
}