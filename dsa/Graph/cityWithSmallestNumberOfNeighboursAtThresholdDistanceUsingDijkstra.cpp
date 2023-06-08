
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<vector<int>> dist;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({0, i});
            vector<int> temp(n, 1e9);
            temp[i] = 0;
            while (!pq.empty())
            {
                int dst = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                for (auto it : adj[node])
                {
                    int adjNode = it.first;
                    int d = it.second;
                    if (dst + d < temp[adjNode])
                    {
                        temp[adjNode] = dst + d;
                        pq.push({temp[adjNode], adjNode});
                    }
                }
            }
            dist.push_back(temp);
        }

        int cntCity = n;
        int cityNo = -1;
        for (int city = 0; city < n; city++)
        {
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++)
            {
                if (dist[city][adjCity] <= distanceThreshold)
                {
                    cnt += 1;
                }
            }
            if (cnt <= cntCity)
            {
                cityNo = city;
                cntCity = cnt;
            }
        }

        return cityNo;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}
