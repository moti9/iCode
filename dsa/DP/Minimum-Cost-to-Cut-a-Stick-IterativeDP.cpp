#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        vector<int> copyCuts(m + 2);
        copy(cuts.begin(), cuts.end(), copyCuts.begin() + 1);
        copyCuts[m + 1] = n;

        sort(copyCuts.begin(), copyCuts.end());
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        for (int i = m; i >= 1; i--)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i > j)
                    continue;
                int minCost = 1e9;

                for (int ind = i; ind <= j; ind++)
                {
                    int cost = copyCuts[j + 1] - copyCuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    minCost = min(minCost, cost);
                }

                dp[i][j] = minCost;
            }
        }
        return dp[1][m];
    }
};

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