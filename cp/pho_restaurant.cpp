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
    // cin>>ttt;
    while (ttt--)
    {
        ll n;
        cin >> n;
        ll maz0 = 0, maz1 = 0, sm = 0, move = 0;
        // ll mn0 = 1e9, cnt1_mn0 = 0;
        // ll mn1 = 1e9, cnt0_mn1 = 0;
        ll t_cnt0 = 0, t_cnt1 = 0;
        ll min_diff = 1e9;
        for (ll i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            ll cnt0 = count(s.begin(), s.end(), '0');
            t_cnt0 += cnt0;
            ll cnt1 = s.length() - cnt0;
            t_cnt1 += cnt1;
            if (cnt0 == cnt1)
            {
                sm += 1;
                move += cnt0;
            }
            else if (cnt0 > cnt1)
            {
                move += cnt1;
                maz0 += 1;
            }
            else
            {
                move += cnt0;
                maz1 += 1;
            }
            // if (cnt0 < mn0)
            // {
            //     mn0 = cnt0;
            //     cnt1_mn0 = cnt1;
            // }
            // if (cnt1 < mn1)
            // {
            //     mn1 = cnt1;
            //     cnt0_mn1 = cnt0;
            // }
            min_diff = min(min_diff, abs(cnt0 - cnt1));
        }
        if (t_cnt0 == 0 || t_cnt1 == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        // if (maz0 > 0 && maz1 == 0)
        // {
        //     if (mn0 > cnt1_mn0)
        //     {
        //         move -= cnt1_mn0;
        //         move += mn0;
        //     }
        // }
        // else if (maz1 > 0 && maz0 == 0)
        // {
        //     if (mn1 > cnt0_mn1)
        //     {
        //         move -= cnt0_mn1;
        //         move += mn1;
        //     }
        // }
        if ((maz0 > 0 && maz1 > 0) || move == 0)
        {
            cout << move << "\n";
        }
        else
        {
            cout << move + min_diff << "\n";
        }
    }
    return 0;
}