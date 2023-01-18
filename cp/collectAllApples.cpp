#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int solve(int node, int parent, vector<int> adj[], vector<bool> hasApple)
{
    int time = 0;
    for (auto child : adj[node])
    {
        if (child == parent)
        {
            continue;
        }
        int tm = solve(child, node, adj, hasApple);
        if (tm > 0 || hasApple[child])
        {
            time += (tm + 2);
        }
    }
    return time;
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return solve(0, -1, adj, hasApple);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    vector<bool> hasApple(n);
    for (int i = 0; i < n; i++)
    {
        bool x;
        cin >> x;
        hasApple[i] = x;
    }

    cout << minTime(n, edges, hasApple) << endl;

    return 0;
}