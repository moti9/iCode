#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n, m;
    cin >> n >> m;
    // n-nodes , m-edges

    // int adj[n + 1][n + 1] = {{0}};
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }

    // For weighted graph
    // int adj[n + 1][n + 1] = {{0}};
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v,wt;
    //     cin >> u >> v>>wt;
    //     adj[u][v] = wt;
    //     adj[v][u] = wt;
    // }

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for weighted graph
    // vector<pair<int, int>> adj[n + 1];
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v, wt;
    //     cin >> u >> v >> wt;
    //     adj[u].push_back({v, wt});
    //     adj[v].push_back({u, wt});
    // }
    return 0;
}