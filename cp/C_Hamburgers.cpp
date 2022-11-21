#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    string rec;
    cin >> rec;
    ll b, s, c;
    cin >> b >> s >> c;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;
    ll cb = 0, cs = 0, cc = 0;
    for (auto x : rec)
    {
        if (x == 'B')
        {
            cb += 1;
        }
        else if (x == 'S')
        {
            cs += 1;
        }
        else
        {
            cc += 1;
        }
    }
    ll low = 0, high = r + 102;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll r1 = max(cb * mid - b, 0LL);
        ll r2 = max(cs * mid - s, 0LL);
        ll r3 = max(cc * mid - c, 0LL);
        ll pr = r1 * pb + r2 * ps + r3 * pc;
        if (pr <= r)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << high;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
