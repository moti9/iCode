#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isPalindrome(int st, int end, string s)
{
    while (st <= end)
    {
        if (s[st++] != s[end--])
            return false;
    }
    return true;
}

void partitionOfStr(int ind, string s, vector<vector<string>> &ans, vector<string> ds)
{
    if (ind == s.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(ind, i, s))
        {
            ds.push_back(s.substr(ind, i - ind + 1));
            partitionOfStr(i + 1, s, ans, ds);
            ds.pop_back();
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<vector<string>> ans;
    vector<string> ds;
    partitionOfStr(0, s, ans, ds);

    for (auto x : ans)
    {
        for (auto str : x)
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}