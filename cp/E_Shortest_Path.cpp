#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // unordered_map<string, int> mp;
        set<vector<int>> st;
        for (int i = 0; i < k; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            st.insert({a, b, c});
            // string path = to_string(a) + "-" + to_string(b) + "-" + to_string(c);
            // mp[path]++;
            // cout << path << "\n";
        }
        // vector<int> path, vis(n + 1);
        // path.push_back(1);
        // queue<int> q;
        // q.push(1);
        // vis[1] = 1;
        vector<vector<int>> dist(n + 1, vector<int>(n + 1));
        // dist[1][0] = 0;
        int last = -1;
        queue<pair<int, int>> q;
        q.push({1, 1});
        dist[1][1] = -1;
        bool foundPath = false;
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            if (node == n)
            {
                foundPath = true;
                last = parent;
                break;
            }

            for (auto &ch : adj[node])
            {
                if (st.count({parent, node, ch}) || dist[node][ch])
                    continue;
                dist[node][ch] = parent;
                q.push({ch, node});
            }

            // string curr = "";
            // if (path.size() > 1)
            // {
            //     int len = path.size();
            //     curr = to_string(path[n - 2]) + "-" + to_string(path[n - 1]) + "-";
            // }
            // for (auto &ch : adj[node])
            // {
            //     if (!vis[ch])
            //     {
            //         if (mp[curr + to_string(ch)] == 0)
            //         {
            //             q.push(ch);
            //             vis[ch] = 1;
            //             path.push_back(ch);
            //         }
            //     }
            // }
        }
        if (foundPath)
        {
            vector<int> path;
            int src = last, dest = n;
            while (src != -1)
            {
                path.push_back(dest);
                int temp = src;
                src = dist[temp][dest];
                dest = temp;
            }
            reverse(path.begin(), path.end());
            cout << path.size() - 1 << "\n";
            for (auto &p : path)
                cout << p << " ";
            cout << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}