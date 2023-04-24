#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(int ind, string dig, vector<string> &ans, unordered_map<char, string> mp, string ds)
{
    if (ind >= dig.size())
    {
        ans.push_back(ds);
        return;
    }
    string st = mp[dig[ind]];
    for (int i = 0; i < st.size(); i++)
    {
        solve(ind + 1, dig, ans, mp, ds + st[i]);
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    unordered_map<char, string> mp;
    char ch = '2', st = 'a';
    while (ch <= '9')
    {
        if (ch == '7' || ch == '9')
        {
            int i = 0;
            string s = "";
            while (i < 4)
            {
                s += st;
                st++;
                i++;
            }
            mp[ch] = s;
        }
        else
        {
            int i = 0;
            string s = "";
            while (i < 3)
            {
                s += st;
                st++;
                i++;
            }
            mp[ch] = s;
        }
        ch++;
    }
    // for (auto x : mp)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }
    solve(0, digits, ans, mp, "");
    return ans;
}

int main()
{
    string digit;
    cin >> digit;
    vector<string> ans = letterCombinations(digit);
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}