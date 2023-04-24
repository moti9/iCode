#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    string s, t;
    cin >> s;
    cin >> t;
    bool flag = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[n - 1 - i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif

    ll test = 1;
    //cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
