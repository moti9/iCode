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
        int n, m;
        cin >> n >> m;
        if (m & 1)
        {
            int cnt = n * (m - 3) / 2 + n;
            cout << cnt << "\n";
        }
        else
        {
            int cnt = n * (m / 2);
            cout << cnt << "\n";
        }
    }
    return 0;
}