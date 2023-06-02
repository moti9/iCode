#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> indegree(V);
        for (int i = 0; i < V; i++)
        {
            for (auto adn : adj[i])
            {
                indegree[adn]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
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
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.topoSort(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}