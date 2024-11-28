#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll count_bit(ll n)
{
    ll ans = 0;
    ll set_cnt = 2;
    while (n > 0)
    {
        if (n > 0)
        {
            n -= 1;
            ans += 1;
        }
        if (n >= set_cnt)
        {
            ans += set_cnt;
            n -= set_cnt;
            set_cnt *= 2;
        }
        else
        {
            ans += n;
            n = 0;
        }
    }
    if (n > 0)
    {
        ans += n;
    }
    return ans;
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
        ll k;
        cin >> k;

        if (k == 1)
        {
            cout << 2 << "\n";
        }
        else
        {
            ll left = k + 1, right = 2 * k + 1;
            ll ans = 0;
            while (left <= right)
            {
                ll mid = (left + right) / 2;
                ll bits = count_bit(mid);
                if (bits == k)
                {
                    ans = mid;
                    right = mid - 1;
                }
                else if (bits > k)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            cout << ans << "\n";
        }
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