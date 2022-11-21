#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    string s, t;
    cin >> s;
    cin >> t;
    int slen = s.size();
    int tlen = t.size();
    int lcm_st = (slen * tlen) / __gcd(slen, tlen);
    string scp = "", tcp = "";
    int srep = lcm_st / slen;
    int trep = lcm_st / tlen;
    for (int i = 0; i < max(srep, trep); i++)
    {
        if (i < srep)
        {
            scp += s;
        }
        if (i < trep)
        {
            tcp += t;
        }
    }
    if (scp == tcp)
    {
        cout << scp << "\n";
    }
    else
    {
        cout << "-1\n";
    }
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
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
