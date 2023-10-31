#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minChanges(string s)
    {
        int n = s.length();
        int cntOdd = 0;
        vector<pair<int, int>> vp;
        for (int i = 0; i < n;)
        {
            int start = i;
            int end = i;
            while (end < n && s[start] == s[end])
            {
                end += 1;
            }
            int len = end - start;
            if (len & 1)
            {
                cntOdd += 1;
            }
            vp.push_back({start, end - 1});
            i = end;
        }
        if (cntOdd == 0)
            return 0;
        int ops = 0;
        for (int i = 0; i < vp.size() - 1; i++)
        {
            int len1 = vp[i].second - vp[i].first + 1;
            if (len1 % 2 == 0)
                continue;
            int len2 = vp[i + 1].second - vp[i + 1].first + 1;
            if ((len1 & 1) && (len2 & 1))
            {
                ops += 1;
                i += 1;
            }
            else if (len1 & 1)
            {
                ops += 1;
                vp[i + 1].first += 1;
            }
        }
        return ops;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minChanges(s) << endl;

    return 0;
}