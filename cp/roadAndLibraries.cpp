#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> &graph)
{
    vis[node] = 1;
    int cnt = 1;
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (!vis[graph[node][i]])
        {
            cnt += dfs(graph[node][i], vis, graph);
        }
    }
    return cnt;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
    if (c_lib <= c_road)
    {
        return (long)n * (long)c_lib;
    }
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < cities.size(); i++)
    {
        graph[cities[i][0]].push_back(cities[i][1]);
        graph[cities[i][1]].push_back(cities[i][0]);
    }

    vector<int> comps;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() > 0 && !vis[i])
        {
            comps.push_back(dfs(i, vis, graph));
        }
        else if (graph[i].size() == 0)
        {
            comps.push_back(1);
        }
    }

    long ans = 0;
    for (int i = 0; i < comps.size(); i++)
    {
        ans += min((long)(comps[i] - 1) * (long)c_road + (long)c_lib, (long)comps[i] * (long)c_lib);
    }
    return ans;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m, c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;
        vector<vector<int>> cities;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            cities.push_back({u, v});
        }
        cout << roadsAndLibraries(n, c_lib, c_road, cities) << "\n";
    }

    return 0;
}