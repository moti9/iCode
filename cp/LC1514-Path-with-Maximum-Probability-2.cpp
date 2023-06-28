#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Shortest Path Fastest Algorithm

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        int m = succProb.size();
        vector<pair<int, double>> graph[n];
        for (int i = 0; i < m; i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto adjNode : graph[node])
            {
                int adj = adjNode.first;
                double prob = adjNode.second;

                if (maxProb[node] * prob > maxProb[adj])
                {
                    maxProb[adj] = maxProb[node] * prob;
                    q.push(adj);
                }
            }
        }

        return maxProb[end];
    }
};


int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<double> succProb(m);
    for (int i = 0; i < m; i++)
    {
        cin >> succProb[i];
    }

    int start, end;
    cin >> start >> end;

    Solution sol;
    cout << sol.maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}