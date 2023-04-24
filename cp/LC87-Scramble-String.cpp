#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
    bool solve(string s1, string s2, unordered_map<string, bool> &dp)
    {
        if (s1 == s2)
        {
            return true;
        }
        string key = s1 + s2;
        if (dp.count(key))
        {
            return dp[key];
        }
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        vector<int> c(26, 0);
        int n = s1.size();

        for (int i = 1; i < n; i++)
        {
            int j = n - i;
            a[s1[i - 1] - 'a'] += 1;
            b[s2[i - 1] - 'a'] += 1;
            c[s2[j] - 'a'] += 1;
            if (a == b && solve(s1.substr(0, i), s2.substr(0, i), dp) && solve(s1.substr(i), s2.substr(i), dp))
            {
                dp[key] = true;
                return true;
            }
            if (a == c && solve(s1.substr(0, i), s2.substr(j), dp) && solve(s1.substr(i), s2.substr(0, j), dp))
            {
                dp[key] = true;
                return true;
            }
        }
        dp[key] = false;
        return false;
    }

public:
    bool isScramble(string s1, string s2)
    {
        unordered_map<string, bool> dp;
        return solve(s1, s2, dp);
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.isScramble(s1, s2) << endl;

    return 0;
}