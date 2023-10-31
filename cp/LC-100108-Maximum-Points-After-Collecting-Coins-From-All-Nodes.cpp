#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void dfs(int u, int parent, const vector<vector<int>> &adj, const vector<int> &coins, int k, vector<vector<int>> &dp)
    {
        dp[u][0] = coins[u];
        for (int v : adj[u])
        {
            if (v == parent)
                continue;
            dfs(v, u, adj, coins, k, dp);
            for (int i = 1; i <= k; i++)
            {
                dp[u][i] = max(dp[u][i], dp[v][i - 1] + max(0, coins[u] - i));

                dp[u][i] = max(dp[u][i], dp[v][i] + (dp[u][0] / 2));
            }
        }
    }

public:
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
    {
        int n = coins.size();

        vector<vector<int>> adj(n);
        for (const vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        dfs(0, -1, adj, coins, k, dp);

        return dp[0][k];
    }
};

int main()
{

    return 0;
}