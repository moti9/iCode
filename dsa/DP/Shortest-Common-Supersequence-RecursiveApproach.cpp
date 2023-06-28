#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int longestCommon(int ind1, int ind2, string &str1, string &str2)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }

        if (str1[ind1] == str2[ind2])
        {
            return 1 + longestCommon(ind1 - 1, ind2 - 1, str1, str2);
        }
        else
        {
            return 0 + max(longestCommon(ind1 - 1, ind2, str1, str2), longestCommon(ind1, ind2 - 1, str1, str2));
        }
    }

public:
    int shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        int lcs = longestCommon(n - 1, m - 1, str1, str2);

        return n + m - lcs;
    }
};

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    Solution sol;
    cout << sol.shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}