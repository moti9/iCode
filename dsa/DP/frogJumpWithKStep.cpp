#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Recursive
int findMinEnergy(int n, int k, vector<int> height)
{
    if (n == 0)
    {
        return 0;
    }
    int mnSteps = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int jmp = findMinEnergy(n - i, k, height) + abs(height[n] - height[i]);
            mnSteps = min(mnSteps, jmp);
        }
        else
        {
            break;
        }
    }
    return mnSteps;
}

// Memoization
int findMinEnergy(int n, int k, vector<int> height, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int mnSteps = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            int jmp = findMinEnergy(n - i, k, height) + abs(height[n] - height[i]);
            mnSteps = min(mnSteps, jmp);
        }
        else
        {
            break;
        }
    }
    return dp[n] = mnSteps;
}

// Tabulization
void findMinEnergy(int k, vector<int> height, vector<int> &dp)
{
    dp[0] = 0;

    for (int i = 1; i < height.size(); i++)
    {
        int mnSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jmp = dp[i - j] + abs(height[i] - height[j]);
                mnSteps = min(mnSteps, jmp);
            }
            else
            {
                break;
            }
        }
        dp[i] = mnSteps;
    }
}

// Space Optimization
/*
    We can't optimize space because in worst case if the k==n then the SC will be O(N)
    because we carry an array of size k.

*/

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    int k;
    cin >> k;

    cout << findMinEnergy(n - 1, k, height) << endl;

    vector<int> dp(n, -1); // For tabular    vector<int> dp(n, 0) also valid

    // cout << findMinEnergy(n - 1, k, height, dp) << endl;

    findMinEnergy(k, height, dp);
    cout << dp[n - 1] << endl;

    return 0;
}