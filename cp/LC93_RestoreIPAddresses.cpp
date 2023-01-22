#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool check(int n, string s)
    {
        vector<string> arr;
        string st = "";
        int ind = 0;
        while (s[ind] != '\0')
        {
            if (s[ind] == '.')
            {
                st = "";
                arr.push_back(st);
            }
            st += s[ind];
            ind++;
        }
        int sz = arr.size();
        if (sz < 4 || sz > 4)
        {
            return false;
        }
        int tlen = 0;
        for (auto x : arr)
        {
            if (x == "" || x > "255" || (x[0] == '0' && x.size() > 1))
            {
                return false;
            }
            tlen += x.size();
        }
        if (tlen != n)
        {
            return false;
        }
        return true;
    }
    void solve(int ind, int n, string &s, string ds, vector<string> &ans)
    {
        if (ind >= n)
        {
            if (check(n, ds))
            {
                ans.push_back(ds);
            }
            return;
        }
        ds += s[ind];
        solve(ind + 1, n, s, ds + '.', ans);
        solve(ind + 1, n, s, ds, ans);
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        int n = s.size();
        vector<string> ans;
        if (n > 12)
        {
            return ans;
        }
        solve(0, n, s, "", ans);
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    vector<string> ans = sol.restoreIpAddresses(s);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}