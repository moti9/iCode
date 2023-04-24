#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cA = 0, cD = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            cA++;
        }
        else
        {
            cD++;
        }
    }
    if (cA > cD)
    {
        cout << "Anton\n";
    }
    else if (cA == cD)
    {
        cout << "Friendship\n";
    }
    else
    {
        cout << "Danik\n";
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
