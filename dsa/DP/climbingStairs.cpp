#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int findWays(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return findWays(n - 1) + findWays(n - 2);
}

// Memoization
int findWays(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = findWays(n - 1) + findWays(n - 2);
}

// Tabular
void findWay(int n, vector<int> &dp)
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

// Space Optimization
int findWay(int n)
{
    int prev = 1, prev2 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    cout << findWays(n) << endl;
    vector<int> dp(n + 1, -1);
    // cout << findWays(n, dp) << endl;

    // findWay(n, dp);
    // cout << dp[n] << endl;

    cout << findWay(n) << endl;

    return 0;
}