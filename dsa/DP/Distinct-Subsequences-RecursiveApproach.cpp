#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int countDistinctSubseq(int i, int j, string &s, string &t)
    {
        if (j < 0)
        {
            return 1;
        }
        if (i < 0)
        {
            return 0;
        }
        int cnt = 0;
        if (s[i] == t[j])
        {
            cnt += countDistinctSubseq(i - 1, j - 1, s, t);
        }
        cnt += countDistinctSubseq(i - 1, j, s, t);
        return cnt;
    }

public:
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        return countDistinctSubseq(n - 1, m - 1, s, t);
    }
};

int main()
{
    string s, t;
    cin >> s >> t;

    Solution sol;
    cout << sol.numDistinct(s, t) << endl;

    return 0;
}