#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool wordPattern(string pattern, string s)
{
    vector<string> str;
    unordered_map<char, string> mp;
    string temp = "";
    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            str.push_back(temp);
        }
        else
        {
            temp += s[i];
        }
    }
    str.push_back(temp);
    if (str.size() != pattern.size())
    {
        return false;
    }
    set<string> st;
    for (int i = 0; i < pattern.size(); i++)
    {
        if (mp.find(pattern[i]) != mp.end())
        {
            if (mp[pattern[i]] != str[i])
            {
                return false;
            }
        }
        else
        {
            if (st.count(str[i]) > 0)
                return false;
            mp[pattern[i]] = str[i];
            st.insert(str[i]);
        }
    }
    return true;
}

int main()
{
    string s, p;
    cin >> p;
    cin >> s;
    cout << wordPattern(p, s) << endl;

    return 0;
}