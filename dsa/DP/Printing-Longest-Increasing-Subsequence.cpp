#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int longestSubsequence(int n, int arr[])
    {
        vector<int> dp(n, 1), hash(n);

        int maxLen = 0;
        int lastIndex = 0;

        for (int ind = 0; ind < n; ind++)
        {
            hash[ind] = ind;

            for (int prev = 0; prev < ind; prev++)
            {
                if (arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            if (dp[ind] > maxLen)
            {
                maxLen = dp[ind];
                lastIndex = ind;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }

        reverse(temp.begin(), temp.end());

        for (auto &t : temp)
        {
            cout << t << " ";
        }
        cout << endl;

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