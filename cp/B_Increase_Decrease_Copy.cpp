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

        vector<int> a(n), b(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i <= n; i++)
        {
            cin >> b[i];
        }

        ll ops = 0;
        int mini = 1e9;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            ops += (ll)abs(a[i] - b[i]);
            mini = min({mini, abs(a[i] - b[n]) + 1, abs(b[i] - b[n]) + 1});
            if (a[i] <= b[i])
            {
                if (a[i] <= b[n] && b[n] <= b[i])
                    flag = true;
            }
            else
            {
                if (b[i] <= b[n] && b[n] <= a[i])
                    flag = true;
            }
        }
        if (flag)
            ops += 1;
        else
            ops += (ll)mini;
        cout << ops << "\n";
    }
    return 0;
}