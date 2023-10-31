#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    const int MOD = 1e9 + 7;

    long long countPermutations(int n, int prev, vector<vector<long long>> &dp)
    {
        if (n == 0)
            return 1;

        if (dp[n][prev] != -1)
        {
            return dp[n][prev];
        }

        long long count = 0;

        if (prev == 0)
        {
            count = (count + countPermutations(n - 1, 1, dp) % MOD) % MOD;
        }
        else if (prev == 1)
        {
            count = (count + countPermutations(n - 1, 0, dp) % MOD) % MOD;
            count = (count + countPermutations(n - 1, 2, dp) % MOD) % MOD;
        }
        else if (prev == 2)
        {
            count = (count + countPermutations(n - 1, 0, dp) % MOD) % MOD;
            count = (count + countPermutations(n - 1, 1, dp) % MOD) % MOD;
            count = (count + countPermutations(n - 1, 3, dp) % MOD) % MOD;
            count = (count + countPermutations(n - 1, 4, dp) % MOD) % MOD;
        }
        else if (prev == 3)
        {
            count = (count + countPermutations(n - 1, 2, dp) % MOD) % MOD;
            count = (count + countPermutations(n - 1, 4, dp) % MOD) % MOD;
        }
        else if (prev == 4)
        {
            count = (count + countPermutations(n - 1, 0, dp) % MOD) % MOD;
        }

        dp[n][prev] = count;
        return count;
    }

public:
    int countVowelPermutation(int n)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(5, -1));
        int count = 0;

        for (int i = 0; i < 5; i++)
        {
            count = (count + countPermutations(n - 1, i, dp) % MOD) % MOD;
        }

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