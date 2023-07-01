#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int longestSubsequence(int n, int arr[])
    {
        vector<int> dp(n, 1);

        int maxLen = 0;
        for (int ind = 1; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (arr[prev] < arr[ind])
                {
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
            maxLen = max(maxLen, dp[ind]);
        }

        return maxLen;
    }
};

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.longestSubsequence(n, a) << endl;
    }
}