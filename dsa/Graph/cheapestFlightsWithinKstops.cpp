#include <bits/stdc++.h>
using namespace std;

// TC- O(E)==O(M)
// SC- O(N*M)

class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {

        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> cost(n, 1e9);
        cost[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int city = it.second.first;
            int c_cost = it.second.second;

            if (stops > K)
            {
                continue;
            }

            for (auto iter : adj[city])
            {
                int near_city = iter.first;
                int t_cost = iter.second;

                if (c_cost + t_cost < cost[near_city])
                {
                    cost[near_city] = c_cost + t_cost;
                    q.push({stops + 1, {near_city, cost[near_city]}});
                }
            }
        }

        if (cost[dst] == 1e9)
        {
            return -1;
        }

        return cost[dst];
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int edge;
        cin >> edge;
        vector<vector<int>> flights;

        for (int i = 0; i < edge; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }

        int src, dst, k;
        cin >> src >> dst >> k;
        Solution obj;
        cout << obj.CheapestFLight(n, flights, src, dst, k) << "\n";
    }
    return 0;
}
