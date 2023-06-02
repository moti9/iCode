#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &safe)
    {
        vis[node] += 2;
        for (auto adjNode : adj[node])
        {
            if (vis[adjNode] == 0)
            {
                if (dfs(adjNode, adj, vis, safe))
                {
                    return true;
                }
            }
            else if (vis[adjNode] == 2)
            {
                return true;
            }
        }
        vis[node] -= 1;
        safe.push_back(node);
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> safe;
        vector<int> vis(V);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, safe);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
