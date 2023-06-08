#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        dist[1] = 0;

        while (!pq.empty())
        {
            int dst = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWt = it.second;

                if (dst + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = dst + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if (dist[n] == 1e9)
        {
            return {-1};
        }
        vector<int> shortest_path;
        int node = n;
        while (parent[node] != node)
        {
            shortest_path.push_back(node);
            node = parent[node];
        }
        shortest_path.push_back(1);
        reverse(shortest_path.begin(), shortest_path.end());

        return shortest_path;
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
