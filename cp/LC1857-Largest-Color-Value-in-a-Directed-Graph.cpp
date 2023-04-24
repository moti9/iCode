#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int dfs(int node, vector<int> adj[], string &colors, vector<vector<int>> &cnt, vector<bool> &vis, vector<bool> &inStack)
    {
        if (inStack[node])
        {
            return INT_MAX;
        }
        if (vis[node])
        {
            return cnt[node][colors[node] - 'a'];
        }
        vis[node] = true;
        inStack[node] = true;
        for (auto adjNode : adj[node])
        {
            if (dfs(adjNode, adj, colors, cnt, vis, inStack) == INT_MAX)
            {
                return INT_MAX;
            }
            for (int i = 0; i < 26; i++)
            {
                cnt[node][i] = max(cnt[node][i], cnt[adjNode][i]);
            }
        }
        inStack[node] = false;
        cnt[node][colors[node] - 'a']++;
        return cnt[node][colors[node] - 'a'];
    }

public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<int> adj[n];
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
        }
        vector<bool> vis(n, false), inStack(n, false);
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dfs(i, adj, colors, cnt, vis, inStack));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    string colors;
    cin >> colors;
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution sol;
    cout << sol.largestPathValue(colors, edges) << endl;

    return 0;
}