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
            return max(longestCommon(ind1 - 1, ind2, str1, str2), longestCommon(ind1, ind2 - 1, str1, str2));
        }
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        int lcs = longestCommon(n - 1, m - 1, word1, word2);

        return n + m - 2 * lcs;
    }
};

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    Solution sol;
    cout << sol.minDistance(str1, str2) << endl;

    return 0;
}