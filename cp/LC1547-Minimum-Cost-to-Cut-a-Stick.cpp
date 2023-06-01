#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int cost(int left, int right, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }
        if (right - left == 1)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int mid = left + 1; mid < right; mid++)
        {
            int temp = cost(left, mid, cuts, dp) + cost(mid, right, cuts, dp) + cuts[right] - cuts[left];
            ans = min(ans, temp);
        }
        return dp[left][right] = ans;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, -1));
        vector<int> newCuts(m + 2);
        copy(cuts.begin(), cuts.end(), newCuts.begin() + 1);
        newCuts[m + 1] = n;
        sort(newCuts.begin(), newCuts.end());

        return cost(0, m + 1, newCuts, dp);
    }
};

/*
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        vector<vector<int>> dp(m + 2, vector<int>(m + 2));
        vector<int> newCuts(m + 2);
        copy(cuts.begin(), cuts.end(), newCuts.begin() + 1);
        newCuts[m + 1] = n;
        sort(newCuts.begin(), newCuts.end());

        for (int diff = 2; diff < m + 2; ++diff)
        {
            for (int left = 0; left < m + 2 - diff; ++left)
            {
                int right = left + diff;
                int ans = INT_MAX;
                for (int mid = left + 1; mid < right; ++mid)
                {
                    ans = min(ans, dp[left][mid] + dp[mid][right] + newCuts[right] - newCuts[left]);
                }
                dp[left][right] = ans;
            }
        }

        return dp[0][m + 1];
    }
};
*/

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> cuts(m);
    for (int i = 0; i < m; i++)
    {
        cin >> cuts[i];
    }

    Solution sol;
    cout << sol.minCost(n, cuts) << endl;

    return 0;
}