#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N)
// SC- O(N + N)

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == s[n - j])
                {
                    curr[j] = 1 + dp[j - 1];
                }
                else
                {
                    curr[j] = max(dp[j], curr[j - 1]);
                }
            }
            dp = curr;
        }
        return dp[n];
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;

    cout << sol.longestPalindromeSubseq(s) << endl;

    return 0;
}