#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;
        int num_edges = 0;
        // int num_nodes = 1;
        for (int neighbor : adj[node])
        {
            // num_nodes += 1;
            if (!visited[neighbor])
            {
                num_edges++;
                num_edges += dfs(neighbor, adj, visited);
            }
        }
        return num_edges == (int)(adj[node].size()) - 1;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited))
                {
                    components++;
                }
            }
        }
        return components;
    }
};

int main()
{

    return 0;
}