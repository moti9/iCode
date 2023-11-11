#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Graph
{
    vector<vector<int>> adj;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        adj = vector<vector<int>>(n, vector<int>(n, 1e9));
        for (auto &edge : edges)
        {
            adj[edge[0]][edge[1]] = edge[2];
        }
        for (int i = 0; i < n; i++)
        {
            adj[i][i] = 0;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge)
    {
        int n = adj.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][edge[0]] + adj[edge[1]][j] + edge[2]);
            }
        }
    }

    int shortestPath(int node1, int node2)
    {
        return (adj[node1][node2] == 1e9) ? -1 : adj[node1][node2];
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