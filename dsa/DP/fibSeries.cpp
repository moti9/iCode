#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int fibNumber(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibNumber(n - 1) + fibNumber(n - 2);
}

// Memoization
int fibNumber(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fibNumber(n - 1, dp) + fibNumber(n - 2, dp);
}

// Tabular
void fibNumbers(int n, vector<int> &dp)
{
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

// Space Optimization
int fibNumbers(int n)
{
    int prev2 = 0;
    int prev = 1;
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

    // int dp[n+1];
    // memset(dp,-1,sizeof(dp));

    vector<int> dp(n + 1, -1);

    cout << fibNumber(n, dp) << endl;

    return 0;
}