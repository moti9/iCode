
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto nb : adj[node])
        {
            if (!vis[nb.first])
            {
                topoSort(nb.first, adj, vis, st);
            }
        }
        st.push(node);
        return;
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
        }
        stack<int> st;
        vector<int> vis(N);
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topoSort(i, adj, vis, st);
            }
        }
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                dist[v] = min(dist[v], dist[node] + wt);
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}
