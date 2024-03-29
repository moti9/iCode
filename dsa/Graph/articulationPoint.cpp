
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int timer = 0;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, int tin[], int low[], vector<int> &mark)
    {

        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer += 1;

        int child = 0;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, adj, vis, tin, low, mark);
                low[node] = min(low[node], low[it]);

                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child += 1;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }

        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> vis(V);
        int tin[V], low[V];
        vector<int> mark(V);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj, vis, tin, low, mark);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
        {
            return {-1};
        }
        return ans;
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
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
