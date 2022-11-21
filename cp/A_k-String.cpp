#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    string ans = "";
    for (auto x : mp)
    {
        if (x.second % n != 0)
        {
            cout << -1;
            return 0;
        }
        else
        {
            for (int i = 1; i <= x.second / n; i++)
            {
                ans += x.first;
            }
        }
    }
    string cp = ans;
    for (int i = 1; i < n; i++)
    {
        ans += cp;
    }
    cout << ans;

    return 0;
}