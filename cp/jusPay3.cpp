#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

vector<long long> dijkstra(vector<vector<int>> &adjList, int start)
{
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
    int n = adjList.size();
    vector<long long> ans(n, INF);
    ans[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        long long dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto &adj : adjList[node])
        {
            if (dist + 1 < ans[adj])
            {
                ans[adj] = dist + 1;
                pq.push({dist + 1, adj});
            }
        }
    }
    return ans;
}

void solution_function()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);

    vector<int> edges;
    for (int i = 0; i < n; ++i)
    {
        int edge;
        cin >> edge;
        if (edge != -1)
            graph[i].push_back(edge);
    }

    int cell1, cell2;
    cin >> cell1 >> cell2;

    vector<long long> meet1(n, INF), meet2(n, INF);

    meet1 = dijkstra(graph, cell1);
    meet2 = dijkstra(graph, cell2);

    int node = -1;
    long long dist = INF;
    for (int i = 0; i < n; ++i)
    {
        if (meet1[i] == INF || meet2[i] == INF)
            continue;
        if (dist > meet1[i] + meet2[i])
        {
            dist = meet1[i] + meet2[i];
            node = i;
        }
    }
    cout << node << "\n";
}

int main()
{
    int test;
    cin >> test;

    for (int tt = 1; tt <= test; tt += 1)
    {
        solution_function();
    }

    return 0;
}