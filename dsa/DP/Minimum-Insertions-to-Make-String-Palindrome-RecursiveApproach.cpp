#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int lcs(int ind1, int ind2, int n, string &s)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }
        if (s[ind1] == s[n - ind2 - 1])
        {
            return 1 + lcs(ind1 - 1, ind2 - 1, n, s);
        }
        else
        {
            return max(lcs(ind1 - 1, ind2, n, s), lcs(ind1, ind2 - 1, n, s));
        }
    }

public:
    int minInsertions(string s)
    {
        int n = s.length();

        return n - lcs(n - 1, n - 1, n, s);
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minInsertions(s) << endl;

    return 0;
}