#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int minEnergy(int n, vector<int> height)
{
    if (n == 0)
    {
        return 0;
    }
    int left = minEnergy(n - 1, height) + abs(height[n] - height[n - 1]), right = INT_MAX;
    if (n > 1)
        right = minEnergy(n - 2, height) + abs(height[n] - height[n - 2]);
    return min(left, right);
}

// Memoization
int findMinEnergy(int n, vector<int> height, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int left = INT_MAX, right = INT_MAX;
    left = findMinEnergy(n - 1, height, dp) + abs(height[n] - height[n - 1]);
    if (n > 1)
        right = findMinEnergy(n - 2, height, dp) + abs(height[n] - height[n - 2]);
    return dp[n] = min(left, right);
}

// Tabulization
void findMinEnergy(vector<int> height, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 1; i < height.size(); i++)
    {
        int right = INT_MAX;
        int left = dp[i - 1] + abs(height[i] - height[i - 1]);
        if (i > 2)
            right = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(left, right);
    }
}

// Space Optimization
int findMinEnergy(vector<int> height)
{
    int prev2 = 0, prev = 0;
    for (int i = 1; i < height.size(); i++)
    {
        int fs = prev + abs(height[i] - height[i - 1]);
        int ss = INT_MAX;
        if (i > 1)
            ss = prev2 + abs(height[i] - height[i - 2]);

        int curri = min(fs, ss);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << minEnergy(n - 1, height) << endl;

    vector<int> dp(n, -1); // For tabular    vector<int> dp(n, 0) also valid

    cout << findMinEnergy(n - 1, height, dp) << endl;

    findMinEnergy(height, dp);
    cout << dp[n - 1] << endl;

    cout << findMinEnergy(height) << endl;

    return 0;
}