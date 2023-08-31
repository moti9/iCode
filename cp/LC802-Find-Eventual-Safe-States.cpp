#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &inStack)
    {
        if (inStack[node] == true)
        {
            return true;
        }
        if (vis[node] == true)
        {
            return false;
        }
        vis[node] = true;
        inStack[node] = true;

        for (auto &adj : graph[node])
        {
            if (dfs(adj, graph, vis, inStack))
            {
                return true;
            }
        }

        inStack[node] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<bool> vis(n, 0), inStack(n, 0);
        for (int i = 0; i < n; i++)
        {
            dfs(i, graph, vis, inStack);
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++)
        {
            if (inStack[i] == 0)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++)
    {
        int m;
        vector<int> adj(m);
        for (int j = 0; j < m; j++)
        {
            cin >> adj[j];
        }
        graph.push_back(adj);
    }

    Solution sol;
    vector<int> ans = sol.eventualSafeNodes(graph);

    for (auto &a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}