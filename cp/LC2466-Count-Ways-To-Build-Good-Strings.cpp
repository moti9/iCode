#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Iterative DP
// TC- O(High)+O(High)
// SC- O(High)

class Solution
{
    int modulus = 1e9 + 7;

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int ans = 0;
        for (int end = 1; end <= high; end++)
        {
            if (end >= zero)
            {
                dp[end] += dp[end - zero];
            }
            if (end >= one)
            {
                dp[end] += dp[end - one];
            }
            dp[end] %= modulus;
        }
        for (int end = low; end <= high; end++)
        {
            ans += dp[end];
            ans %= modulus;
        }
        return ans;
    }
};

// Recursive dp- Memoization
// TC- O(High)+O(High)
// SC- O(High)+O(High)
/*
class Solution
{
    int modulus = 1e9 + 7;
    int solve(int end, int zero, int one, vector<int> &dp)
    {
        if (dp[end] != -1)
            return dp[end];
        int cnt = 0;
        if (end >= zero)
        {
            cnt += solve(end - zero, zero, one, dp);
        }
        if (end >= one)
        {
            cnt += solve(end - one, zero, one, dp);
        }
        cnt %= modulus;
        return dp[end] = cnt;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, -1);
        dp[0] = 1;
        int ans = 0;
        for (int end = low; end <= high; end++)
        {
            ans += solve(end, zero, one, dp);
            ans %= modulus;
        }
        return ans;
    }
};
*/

// Naive Approach- Recursion
/*
class Solution
{
    int modulus = 1e9 + 7;
    int solve(string str, string &zerostr, string &onestr, int low, int high)
    {
        if (str.length() > high)
        {
            return 0;
        }
        int takezero = solve(str + zerostr, zerostr, onestr, low, high) % modulus;
        int takeone = solve(str + onestr, zerostr, onestr, low, high) % modulus;
        int total = (takeone + takezero) % modulus;
        if (str.length() >= low)
            total = (total + 1) % modulus;
        return total;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        string zerostr = "", onestr = "";
        int i = 0;
        while (i < zero && i < one)
        {
            zerostr += "0";
            onestr += "1";
            i += 1;
        }
        while (i < zero)
        {
            zerostr += "0";
            i += 1;
        }
        while (i < one)
        {
            onestr += "1";
            i += 1;
        }
        return solve("", zerostr, onestr, low, high);
    }
};
*/

int main()
{
    int low;
    int high;
    int zero;
    int one;
    cin >> low >> high >> zero >> one;

    Solution sol;
    cout << sol.countGoodStrings(low, high, zero, one);

    return 0;
}