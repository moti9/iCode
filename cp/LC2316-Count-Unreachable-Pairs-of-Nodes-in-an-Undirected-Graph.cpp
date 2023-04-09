#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
    {
        int count = 1;
        vis[node] = true;
        for (int nb : adj[node])
        {
            if (!vis[nb])
            {
                count += dfs(nb, adj, vis);
            }
        }
        return count;
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        long long numpair = 0;
        long long comp = 0;
        long long rmnode = n;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                comp = dfs(i, adj, visit);
                numpair += comp * (rmnode - comp);
                rmnode -= comp;
            }
        }
        return numpair;
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    Solution sol;
    cout << sol.countPairs(n, edges) << endl;

    return 0;
}