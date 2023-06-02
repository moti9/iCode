#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // For components
    bool canColor(int start, vector<int> adj[], vector<int> &color)
    {
        queue<int> nodes;
        nodes.push(start);
        color[start] = 0;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();
            for (auto adjNode : adj[node])
            {
                if (color[adjNode] == -1)
                {
                    color[adjNode] = !color[node];
                    nodes.push(adjNode);
                }
                else if (color[adjNode] == color[node])
                {
                    return false;
                }
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
                if (canColor(i, adj, color) == false)
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
