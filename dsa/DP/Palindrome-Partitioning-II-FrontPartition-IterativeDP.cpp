#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int isPalindrome(int i, int j, string &str)
    {
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return 0;
            }
            i += 1;
            j -= 1;
        }
        return 1;
    }
    
public:
    int minCut(string str)
    {
        int n = str.length();
        vector<int> dp(n + 1, 0);

        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int minParts = n;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, str) == 1)
                {
                    int parts = 1 + dp[j + 1];
                    minParts = min(minParts, parts);
                }
            }
            dp[i] = minParts;
        }
        return dp[0] - 1;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minCut(s) << endl;

    return 0;
}