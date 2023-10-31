#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    const int MOD = 1e9 + 7;
    unordered_map<char, vector<char>> next_vowels = {
        {'a', {'e'}},
        {'e', {'a', 'i'}},
        {'i', {'a', 'e', 'o', 'u'}},
        {'o', {'i', 'u'}},
        {'u', {'a'}}};

    int countPermutations(char prev, int n, unordered_map<int, unordered_map<char, int>> &dp)
    {
        if (n == 0)
            return 1;

        if (dp[n][prev])
            return dp[n][prev];

        int cnt = 0;

        for (char next : next_vowels[prev])
        {
            cnt = (cnt + countPermutations(next, n - 1, dp)) % MOD;
        }

        return dp[n][prev] = cnt;
    }

public:
    int countVowelPermutation(int n)
    {
        unordered_map<int, unordered_map<char, int>> dp;
        int count = 0;

        for (char vowel : {'a', 'e', 'i', 'o', 'u'})
        {
            count = (count + countPermutations(vowel, n - 1, dp)) % MOD;
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