#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string common = "";
        int minSize = 1e7;
        for (auto s : strs)
        {
            int sz = s.size();
            minSize = min(minSize, sz);
        }
        int n = strs.size();
        for (int i = 0; i < minSize; i++)
        {
            char ch = strs[0][i];
            for (int j = 1; j < n; j++)
            {
                if (ch != strs[j][i])
                {
                    return common;
                }
            }
            common += ch;
        }
        return common;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }

    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;

    return 0;
}