#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    bool isCyclic(int V, vector<int> adj[])
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
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt += 1;
            for (auto adn : adj[node])
            {
                indegree[adn]--;
                if (indegree[adn] == 0)
                {
                    q.push(adn);
                }
            }
        }
        return !(cnt == V);
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
