#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(N*M)

class Solution
{
public:
    int lcs(string &str1, string &str2)
    {
        int n = str1.size();
        int m = str2.size();

        vector<int> dp(m + 1, 0), curr(m + 1, 0);
        int maxLen = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    curr[j] = 1 + dp[j - 1];
                    maxLen = max(maxLen, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            dp = curr;
        }
        return maxLen;
    }
};

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    Solution sol;
    cout << sol.lcs(str1, str2) << endl;

    return 0;
}