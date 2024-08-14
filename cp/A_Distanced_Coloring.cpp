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
        int n, m, k;
        cin >> n >> m >> k;

        if (k >= n && k >= m)
        {
            cout << n * m << "\n";
        }
        else
        {
            cout << min(n, k) * min(m, k) << "\n";
        }
    }
    return 0;
}