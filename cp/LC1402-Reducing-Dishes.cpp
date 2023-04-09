#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int solve(int ind, int time, vector<int> &stf, vector<vector<int>> &dp)
    {
        if (ind >= stf.size())
        {
            return 0;
        }
        if (dp[ind][time] != -1)
        {
            return dp[ind][time];
        }
        int pick = time * stf[ind] + solve(ind + 1, time + 1, stf, dp);
        int notpick = solve(ind + 1, time, stf, dp);
        return dp[ind][time] = max(pick, notpick);
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, 1, satisfaction, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> stf(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stf[i];
    }

    return 0;
}