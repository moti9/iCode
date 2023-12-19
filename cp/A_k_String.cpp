#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int k;
    cin >> k;
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    for (auto &c : s)
    {
        mp[c]++;
    }

    string ans = "";
    for (auto &x : mp)
    {
        if (x.second % k != 0)
        {
            cout << "-1\n";
            return;
        }
        else
        {
            ans += string(x.second / k, x.first);
        }
    }

    for (int i = 0; i < k; i++)
    {
        cout << ans;
    }
    cout << "\n";
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
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
