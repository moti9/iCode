#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    int m1 = 1e6, m2 = 1e6, mi = n, mii = n, me = 1e6, mei = n;
    for (int i = 0; i < n; i++)
    {
        int m;
        string s;
        cin >> m >> s;
        if (s[0] == '1' && s[1] == '1')
        {
            if (m < me)
            {
                me = m;
                mei = i;
            }
        }
        if (s[0] == '1')
        {
            if (m < m1)
            {
                m1 = m;
                mi = i;
            }
        }
        if (s[1] == '1')
        {
            if (m < m2)
            {
                m2 = m;
                mii = i;
            }
        }
    }
    if (mi < n && mii < n && mei < n)
    {
        cout << min(m1 + m2, me) << "\n";
        return;
    }
    if (mi < n && mii < n)
    {
        if (mii == mi)
            cout << m1 << "\n";
        else
            cout << m1 + m2 << "\n";
        return;
    }
    cout << "-1\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
