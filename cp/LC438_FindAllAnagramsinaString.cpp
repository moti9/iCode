#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if (n < m)
            return ans;
        vector<int> cp(26, 0), cs(26, 0);
        for (int i = 0; i < m; i++)
        {
            cp[p[i] - 'a']++;
            cs[s[i] - 'a']++;
        }
        if (cs == cp)
            ans.push_back(0);
        for (int i = m; i < n; i++)
        {
            cs[s[i - m] - 'a']--;
            cs[s[i] - 'a']++;
            if (cs == cp)
                ans.push_back(i - m + 1);
        }
        return ans;
    }
};

int main()
{
    string s, p;
    cin >> p >> s;
    Solution sol;
    vector<int> ans = sol.findAnagrams(s, p);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}