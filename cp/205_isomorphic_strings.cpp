
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int lens = s.length();
        int lent = t.length();

        if (lens != lent)
        {
            return false;
        }

        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < lens; i++)
        {
            char cs = s[i];
            char ct = t[i];

            if (sToT.find(cs) == sToT.end())
            {
                sToT[cs] = ct;
            }
            else
            {
                if (sToT[cs] != ct)
                {
                    return false;
                }
            }

            if (tToS.find(ct) == tToS.end())
            {
                tToS[ct] = cs;
            }
            else
            {
                if (tToS[ct] != cs)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;

    Solution sol = Solution();
    bool answer = sol.isIsomorphic(s, t);
    cout << (answer ? "Yes" : "No") << endl;

    return 0;
}