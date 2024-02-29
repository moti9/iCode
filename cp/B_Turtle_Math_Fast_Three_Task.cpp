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
        int cnt1 = 0, cnt2 = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            sum += x;
            cnt2 += (x % 3 == 2);
            cnt1 += (x % 3 == 1);
        }
        if (sum % 3 == 0)
        {
            cout << 0 << "\n";
        }
        else if (sum % 3 == 1)
        {
            if (cnt1 > 0)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 2 << "\n";
            }
        }
        else
        {
            if (cnt1 > 1 || cnt2 > 0)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 2 << "\n";
            }
        }
    }
    return 0;
}