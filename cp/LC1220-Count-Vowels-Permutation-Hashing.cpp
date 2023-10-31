#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    const int MOD = 1e9 + 7;
    int solve(char prev, int n, unordered_map<int, unordered_map<char, int>> &dp)
    {
        if (n == 0)
        {
            return 1;
        }

        if (dp[n][prev])
            return dp[n][prev];

        int cnt = 0;

        if (prev == 'a')
        {
            cnt = (cnt + solve('e', n - 1, dp) % MOD) % MOD;
        }
        else if (prev == 'e')
        {
            cnt = (cnt + solve('a', n - 1, dp) % MOD) % MOD;
            cnt = (cnt + solve('i', n - 1, dp) % MOD) % MOD;
        }
        else if (prev == 'i')
        {
            cnt = (cnt + solve('a', n - 1, dp) % MOD) % MOD;
            cnt = (cnt + solve('e', n - 1, dp) % MOD) % MOD;
            cnt = (cnt + solve('o', n - 1, dp) % MOD) % MOD;
            cnt = (cnt + solve('u', n - 1, dp) % MOD) % MOD;
        }
        else if (prev == 'o')
        {
            cnt = (cnt + solve('i', n - 1, dp) % MOD) % MOD;
            cnt = (cnt + solve('u', n - 1, dp) % MOD) % MOD;
        }
        else if (prev == 'u')
        {
            cnt = (cnt + solve('a', n - 1, dp) % MOD) % MOD;
        }

        return dp[n][prev] = cnt % MOD;
    }

public:
    int countVowelPermutation(int n)
    {
        unordered_map<int, unordered_map<char, int>> dp;
        int count = 0;
        count = (count + solve('a', n - 1, dp) % MOD) % MOD;
        count = (count + solve('e', n - 1, dp) % MOD) % MOD;
        count = (count + solve('i', n - 1, dp) % MOD) % MOD;
        count = (count + solve('o', n - 1, dp) % MOD) % MOD;
        count = (count + solve('u', n - 1, dp) % MOD) % MOD;

        return count;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.countVowelPermutation(n) << endl;

    return 0;
}