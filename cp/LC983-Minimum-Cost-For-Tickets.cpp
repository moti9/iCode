#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int solve(int d, vector<int> &costs, vector<int> &dp, unordered_set<int> dayst)
{
    if (d > 365)
    {
        return 0;
    }
    if (dp[d] != -1)
    {
        return dp[d];
    }

    int ans;
    if (dayst.find(d) != dayst.end())
    {
        ans = min({solve(d + 1, costs, dp, dayst) + costs[0], solve(d + 7, costs, dp, dayst) + costs[1], solve(d + 30, costs, dp, dayst) + costs[2]});
    }
    else
    {
        ans = solve(d + 1, costs, dp, dayst);
    }
    return dp[d] = ans;
}

class Solution
{
    int solve(int d, vector<int> &days, vector<int> &costs, int dur[], vector<int> &dp)
    {
        if (d >= days.size())
        {
            return 0;
        }
        if (dp[d] != -1)
        {
            return dp[d];
        }

        int ans = 1e5;
        int dt = d;
        for (int i = 0; i < 3; i++)
        {
            while (dt < days.size() && days[dt] < days[d] + dur[i])
            {
                dt += 1;
            }
            ans = min(ans, solve(dt, days, costs, dur, dp) + costs[i]);
        }
        return dp[d] = ans;
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int nd = days.size();
        int nc = costs.size();
        vector<int> dp(nd, -1);
        int dur[3] = {1, 7, 30};
        return solve(0, days, costs, dur, dp);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> days(n);
    for (int i = 0; i < n; i++)
    {
        cin >> days[i];
    }

    vector<int> costs(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> costs[i];
    }
    return 0;
}