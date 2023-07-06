#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool checkPossibilities(string &a, string &b)
    {
        if (a.length() != b.length() + 1)
        {
            return false;
        }
        int i = 0, j = 0;
        while (i < a.length())
        {
            if (j < b.length() && a[i] == b[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if (i == a.length() && j == b.length())
            return true;
        else
            return false;
    }
    bool comp(string &a, string &b)
    {
        return (a.length() < b.length());
    }

public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), comp);

        int n = words.size();
        vector<int> dp(n, 1);
        int maxLen = 0;

        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (checkPossibilities(words[ind], words[prev]) == true && 1 + dp[prev] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                }
            }
            maxLen = max(maxLen, dp[ind]);
        }
        return maxLen;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    Solution sol;
    cout << sol.longestStrChain(words) << endl;

    return 0;
}