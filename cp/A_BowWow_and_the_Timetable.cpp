#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    string s;
    cin >> s;
    ll n = s.size();

    ll ct = 0;
    if (n % 2)
    {
        for (ll i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                ct += 1;
            }
        }
    }
    if (ct > 1)
    {
        ct = 1;
    }
    else
    {
        ct = 0;
    }
    cout << (n / 2) + ct;
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
