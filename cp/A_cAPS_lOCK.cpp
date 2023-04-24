#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    string s;
    cin >> s;
    bool flag = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] >= 97)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 97)
            {
                s[i] = s[i] - 32;
            }
            else
            {
                s[i] = s[i] + 32;
            }
        }
    }
    cout << s << "\n";
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

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}