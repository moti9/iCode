#include <bits/stdc++.h>
using namespace std;

// TC- O(V+E)
// SC- O(V+E)

class Solution
{
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs2(it, adj, vis);
            }
        }
        return;
    }

public:
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V);
        stack<int> st;
        // O(V+E)
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        // O(V+E)
        vector<int> adjRev[V];
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                adjRev[it].push_back(i);
            }
        }

        int cntScc = 0;
        // O(V+E)
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                cntScc += 1;
                dfs2(node, adjRev, vis);
            }
        }

        return cntScc;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
