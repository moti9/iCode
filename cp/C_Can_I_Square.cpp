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
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            sum += x;
        }

        ll root = (ll)sqrt(sum);
        if (root * root == sum)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}