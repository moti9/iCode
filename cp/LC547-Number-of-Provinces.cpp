#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using DFS
// TC- O(N*N)
// SC- O(N*N)

class Solution
{
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto nb : adj[node])
        {
            if (!vis[nb])
            {
                dfs(nb, adj, vis);
            }
        }
        return;
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cnt += 1;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> isConnected[i][j];
        }
    }
    Solution sol;
    cout << sol.findCircleNum(isConnected) << endl;
    return 0;
}