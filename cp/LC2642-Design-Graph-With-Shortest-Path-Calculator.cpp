#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Graph
{
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        adj = vector<vector<pair<int, int>>>(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }

    void addEdge(vector<int> edge)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        int n = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e9 + 1);
        pq.push({0, node1});
        dist[node1] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (wt > dist[u])
            {
                continue;
            }

            if (u == node2)
            {
                return wt;
            }

            for (auto &nb : adj[u])
            {
                int v = nb.first;
                int w = nb.second;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

int main()
{
    vector<vector<int>> edges = {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
    Graph g = Graph(4, edges);
    cout << g.shortestPath(3, 2) << endl; // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
    cout << g.shortestPath(0, 3) << endl; // return -1. There is no path from 0 to 3.
    g.addEdge({1, 3, 4});                 // We add an edge from node 1 to node 3, and we get the second diagram above.
    cout << g.shortestPath(0, 3) << endl; // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.
    return 0;
}