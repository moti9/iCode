#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    long long solve(int i, int j, vector<string> &words, string &target, vector<vector<long long>> &dp, vector<vector<int>> &cnt)
    {
        if (j == 0)
        {
            return i == 0 ? 1 : 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        long long ans = solve(i, j - 1, words, target, dp, cnt);
        if (i > 0)
        {
            ans += cnt[j - 1][target[i - 1] - 'a'] * solve(i - 1, j - 1, words, target, dp, cnt);
        }
        ans %= mod;
        return dp[i][j] = ans;
    }

public:
    // Bottom-up Dynamic Programming
    int numWays(vector<string> &words, string target)
    {
        int n = words.size();
        int m = target.size();
        int k = words[0].size();
        vector<vector<int>> cnt(k, vector<int>(26, 0));
        for (int j = 0; j < k; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cnt[j][words[i][j] - 'a'] += 1;
            }
        }
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, -1));
        return solve(m, k, words, target, dp, cnt);
        // vector<vector<long long>> dp(m + 1, vector<long long>(k + 1));
        // dp[0][0] = 1;
        // for (int i = 0; i <= m; i++)
        // {
        //     for (int j = 0; j < k; j++)
        //     {
        //         if (i < m)
        //         {
        //             (dp[i + 1][j + 1] += (dp[i][j] * cnt[j][target[i] - 'a'])) %= mod;
        //         }
        //         (dp[i][j + 1] += (dp[i][j])) %= mod;
        //     }
        // }
        // return dp[m][k];
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
    string target;
    cin >> target;

    Solution sol;
    cout << sol.numWays(words, target) << endl;

    return 0;
}