#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void dfs(int node, vector<int> &edges, vector<bool> &vis, unordered_map<int, int> &dist, int &count)
    {
        vis[node] = true;
        int nb = edges[node];
        if (nb != -1 && !vis[nb])
        {
            dist[nb] = dist[node] + 1;
            dfs(nb, edges, vis, dist, count);
        }
        else if (nb != -1 && dist.find(nb) != dist.end())
        {
            count = max(count, dist[node] - dist[nb] + 1);
        }
    }

public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<bool> vis(n);
        int count = -1;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(i, edges, vis, dist, count);
            }
        }
        return count;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> edges(n);
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i];
    }
    Solution sol;
    cout << sol.longestCycle(edges) << endl;

    return 0;
}