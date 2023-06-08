#include <bits/stdc++.h>
using namespace std;

// TC- O(ElogE)

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V);
        int sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        // ElogE+ElogE
        while (!pq.empty())
        {
            int dst = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (vis[node])
            {
                continue;
            }
            sum += dst;
            vis[node] = 1;
            //ELogE
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int d = it[1];

                if (!vis[adjNode])
                {
                    pq.push({d, adjNode});
                }
            }
        }
        return sum;
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
