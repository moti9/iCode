#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void dfs(int node, vector<int> &edges, vector<int> &dist, vector<bool> &vis)
    {
        vis[node] = true;
        int child = edges[node];
        if (child != -1 && vis[child] == false)
        {
            dist[child] = dist[node] + 1;
            dfs(child, edges, dist, vis);
        }
    }

public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> dist1(n, 0), dist2(n, 0);
        vector<bool> vis1(n, 0), vis2(n, 0);
        dfs(node1, edges, dist1, vis1);
        dfs(node2, edges, dist2, vis2);
        int ans = -1;
        int mini = 1e7;
        for (int i = 0; i < n; i++)
        {
            if (vis1[i] && vis2[i] && mini > max(dist1[i], dist2[i]))
            {
                mini = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
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
    int node1, node2;
    cin >> node1 >> node2;
    Solution sol;
    cout << sol.closestMeetingNode(edges, node1, node2) << endl;

    return 0;
}