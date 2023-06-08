#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltParent(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = findUltParent(parent[u]);
        }
        return parent[u];
    }

    void unionByRank(int u, int v)
    {
        int ultpu = findUltParent(u);
        int ultpv = findUltParent(v);
        if (rank[ultpu] < rank[ultpv])
        {
            parent[ultpu] = ultpv;
        }
        else if (rank[ultpv] < rank[ultpu])
        {
            parent[ultpv] = ultpu;
        }
        else
        {
            parent[ultpv] = ultpu;
            rank[ultpu] += 1;
        }
    }
};

// Kruskal's Algorithm
// TC- O(N*M MlogM+ M*4*alpha*2)
// SC- O(N+M)

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        // N*E
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int node = i;
                int adjNode = it[0];
                int wt = it[1];

                edges.push_back({wt, {node, adjNode}});
            }
        }
        // MlogM
        sort(edges.begin(), edges.end());

        int mstWt = 0;
        DisjointSet ds(V);
        // M*4*alpha*2
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUltParent(u) != ds.findUltParent(v))
            {
                mstWt += wt;
                ds.unionByRank(u, v);
            }
        }

        return mstWt;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
