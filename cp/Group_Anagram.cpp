#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        mp[s].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    vector<vector<string>> ans = groupAnagrams(strs);
    for (auto arr : ans)
    {
        for (auto x : arr)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}