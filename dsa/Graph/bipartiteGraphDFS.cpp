#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int node, int col, vector<int> adj[], vector<int> &color)
    {

        color[node] = col;
        for (auto adjNode : adj[node])
        {
            if (color[adjNode] == -1)
            {
                if (dfs(adjNode, !col, adj, color) == false)
                {
                    return false;
                }
            }
            else if (color[adjNode] == col)
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, adj, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
