#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void calculateFuel(long long node, long long target, long long k, vector<vector<pair<long long, long long>>> &graph, vector<long long> &vis, vector<long long> cost, long long &ans)
    {
        if (node == target)
        {
            sort(cost.rbegin(), cost.rend());
            long long cnt = 0;
            long long fuel = 0;
            for (long long i = 0; i < cost.size(); i++)
            {
                if (cnt < k)
                {
                    fuel += (cost[i] / 2);
                    cnt += 1;
                }
                else
                {
                    fuel += cost[i];
                }
            }
            ans = min(ans, fuel);
        }

        vis[node] = true;
        for (auto adj : graph[node])
        {
            long long nnode = adj.first;
            if (!vis[nnode])
            {
                cost.push_back(adj.second);
                calculateFuel(nnode, target, k, graph, vis, cost, ans);
                cost.pop_back();
            }
        }
        vis[node] = false;
        return;
    }

public:
    int finalDestination(int N, int M, int K, vector<vector<int>> &Roads)
    {
        vector<vector<pair<long long, long long>>> graph(N);
        for (long long i = 0; i < M; i++)
        {
            long long cityA = (long long)Roads[i][0];
            long long cityB = (long long)Roads[i][1];
            long long weight = (long long)Roads[i][2];
            graph[cityA].push_back({cityB, weight});
        }
        vector<long long> vis(N);
        vector<long long> cost;
        long long ans = INT_MAX;
        calculateFuel(0, N - 1, K, graph, vis, cost, ans);
        return ans == INT_MAX ? -1 : (int)ans;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> roads;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        roads.push_back({a, b, w});
    }

    Solution sol;
    cout << sol.finalDestination(n, m, k, roads) << endl;

    return 0;
}