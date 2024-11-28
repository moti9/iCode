#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll allFactors(ll n)
{
    ll fact = 0;
    ll left = -1, right = -1;
    ll lc = 0, rc = 0;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i - left == 1)
            {
                lc += 1;
            }
            else
            {
                lc = 1;
            }
            left = i;

            if (i != (n / i))
            {
                ll ri = n / i;
                if (right - ri == 1)
                {
                    rc += 1;
                }
                else
                {
                    rc = 1;
                }
                right = ri;
            }
        }
        fact = max(fact, lc);
        fact = max(fact, rc);
        if (right - left == 1)
        {
            fact = max(fact, lc + rc);
        }
    }
    return fact;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        ll n;
        cin >> n;

        if (n & 1)
        {
            cout << 1 << "\n";
            continue;
        }

        // ll allFact = allFactors(n);
        // sort(allFact.begin(), allFact.end());

        // ll ans = 1, cnt = 1;
        // ll prev = allFact[0];
        // for (int i = 1; i < allFact.size(); i++)
        // {
        //     if (allFact[i] - prev == 1)
        //     {
        //         cnt += 1;
        //     }
        //     else
        //     {
        //         cnt = 1;
        //     }
        //     prev = allFact[i];
        //     ans = max(ans, cnt);
        // }
        ll ans = -1;
        ll st = 1;
        while (true)
        {
            if (n % st != 0)
            {
                ans = st - 1;
                break;
            }
            st += 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/