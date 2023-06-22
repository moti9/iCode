#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int minCost(int ind, int wall, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp)
    {
        if (wall <= 0)
        {
            return 0;
        }
        if (ind <= 0)
        {
            if (wall <= 0)
            {
                return 0;
            }
            return 1e9;
        }

        if (dp[ind][wall] != -1)
        {
            return dp[ind][wall];
        }

        int notPaint = minCost(ind - 1, wall, cost, time, dp);
        int paint = 1e9;
        if (time[ind] + 1 <= wall)
        {
            paint = cost[ind] + minCost(ind - 1, wall - time[ind] - 1, cost, time, dp);
        }

        return dp[ind][wall] = min(paint, notPaint);
    }

public:
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        // {ind, wall}
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return minCost(n - 1, n, cost, time, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    vector<int> time(n);
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }

    Solution sol;
    cout << sol.paintWalls(cost, time) << endl;

    return 0;
}