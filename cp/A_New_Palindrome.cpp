#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            cnt = 0;
            break;
        }
    }
    if (cnt)
    {
        cout << "NO\n";
        return;
    }
    cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            cnt += 1;
            i += 1;
        }
    }
    if (cnt == 1)
    {
        cout << "NO\n";
        return;
    }
    cnt = 0;

    unordered_map<char, int> mp;
    for (auto c : s)
        mp[c]++;
    for (auto m : mp)
        if (m.second & 1)
            cnt += 1;
    if (cnt <= 1)
        cout << "YES\n";
    else
        cout << "NO\n";
    // unordered_map<char, int> mp;
    // int n = s.length();
    // for (int i = 0; i < n; i++)
    // {
    //     mp[s[i]]++;
    // }
    // if (n & 1)
    //     mp.erase(s[n / 2]);
    // if (mp.size() > 1)
    //     cout << "YES\n";
    // else
    // {
    //     cout << "NO\n";
    // }
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
