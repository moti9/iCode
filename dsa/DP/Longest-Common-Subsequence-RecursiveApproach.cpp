#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N+M)

class Solution
{
public:
    int commonSubseq(int ind1, int ind2, string &text1, string &text2)
    {
        if (ind1 < 0 || ind2 < 0)
        {
            return 0;
        }

        if (text1[ind1] == text2[ind2])
        {
            return 1 + commonSubseq(ind1 - 1, ind2 - 1, text1, text2);
        }
        else
        {
            return 0 + max(commonSubseq(ind1 - 1, ind2, text1, text2), commonSubseq(ind1, ind2 - 1, text1, text2));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {

        int n1 = text1.size();
        int n2 = text2.size();

        if (text1 == text2)
        {
            return n1;
        }
        return commonSubseq(n1 - 1, n2 - 1, text1, text2);
    }
};

int main()
{
    string text1, text2;
    cin >> text1 >> text2;

    Solution sol;
    cout << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}