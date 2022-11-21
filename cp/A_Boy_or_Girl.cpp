#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto x : s)
    {
        mp[x]++;
    }
    if (mp.size() % 2 == 0)
    {
        cout << "CHAT WITH HER!";
    }
    else
    {
        cout << "IGNORE HIM!";
    }

    return 0;
}