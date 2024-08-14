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
        int n, k;
        cin >> n >> k;
        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        if (k == 1)
        {
            cout << n << "\n";
            continue;
        }
        cout << (n - 1) * k + 1 << "\n";
    }
    return 0;
}