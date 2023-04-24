#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }
    unordered_map<char, int> mp;
    for (auto x : s)
    {
        mp[x]++;
    }
    for (auto x : t)
    {
        mp[x]--;
    }
    for (auto x : mp)
    {
        if (x.second != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    cout << isAnagram(s, t) << endl;

    return 0;
}