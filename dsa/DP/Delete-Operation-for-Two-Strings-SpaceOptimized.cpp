#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minDistance(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        vector<int> dp(m + 1), curr(m + 1);

        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (str1[ind1 - 1] == str2[ind2 - 1])
                {
                    curr[ind2] = 1 + dp[ind2 - 1];
                }
                else
                {
                    curr[ind2] = max(dp[ind2], curr[ind2 - 1]);
                }
            }
            dp = curr;
        }
        return n + m - 2 * dp[m];
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