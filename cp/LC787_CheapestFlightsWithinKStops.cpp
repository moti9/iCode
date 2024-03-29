#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Greedy Approach-Try all possible ways
// It's fail in cyclic graph
class Solution
{
    void solve(int src, int dst, int stop, int k, int price, int &cheap, vector<pair<int, int>> adj[])
    {
        if (src == dst)
        {
            cheap = min(cheap, price);
            return;
        }
        if (stop > k)
        {
            return;
        }
        for (auto node : adj[src])
        {
            solve(node.first, dst, stop + 1, k, price + node.second, cheap, adj);
        }
    }

public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto x : flights)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }
        int cheap = INT_MAX;
        solve(src, dst, 0, k, 0, cheap, adj);

        return cheap == INT_MAX ? -1 : cheap;
    }
};
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto x : flights)
    {
        adj[x[0]].push_back({x[1], x[2]});
    }
    vector<int> dist(n, 1e9);
    queue<pair<int, pair<int, int>>> q;
    // Stop-Src-Dist
    q.push({0, {src, 0}});
    dist[src] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stops > k)
        {
            continue;
        }
        for (auto itr : adj[node])
        {
            int adjNode = itr.first;
            int edCost = itr.second;

            if (cost + edCost < dist[adjNode] && stops <= k)
            {
                dist[adjNode] = cost + edCost;
                q.push({stops + 1, {adjNode, dist[adjNode]}});
            }
        }
    }
    return dist[dst] == 1e9 ? -1 : dist[dst];
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> flights;
    for (int i = 0; i < m; i++)
    {
        int f, t, p;
        cin >> f >> t >> p;
        flights.push_back({f, t, p});
    }
    int src, dst, k;
    cin >> src >> dst >> k;

    Solution sol;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;

    return 0;
}

/*
TestCases:

1.
17
114
0 12 28
5 6 39
8 6 59
13 15 7
13 12 38
10 12 35
15 3 23
7 11 26
9 4 65
10 2 38
4 7 7
14 15 31
2 12 44
8 10 34
13 6 29
5 14 89
11 16 13
7 3 46
10 15 19
12 4 58
13 16 11
16 4 76
2 0 12
15 0 22
16 12 13
7 1 29
7 14 100
16 1 14
9 6 74
11 1 73
2 11 60
10 11 85
2 5 49
3 4 17
4 9 77
16 3 47
15 6 78
14 1 90
10 5 95
1 11 30
11 0 37
10 4 86
0 8 57
6 14 68
16 8 3
13 0 65
2 13 6
5 13 5
8 11 31
6 10 20
6 2 33
9 1 3
14 9 58
12 3 19
11 2 74
12 14 48
16 11 100
3 12 38
12 13 77
10 9 99
15 13 98
15 12 71
1 4 28
7 0 83
3 5 100
8 9 14
15 11 57
3 6 65
1 3 45
14 7 74
2 10 39
4 8 73
13 5 77
10 0 43
12 9 92
8 2 26
1 7 7
9 12 10
13 11 64
8 13 80
6 12 74
9 7 35
0 15 48
3 7 87
16 9 42
5 16 64
4 5 65
15 14 70
12 0 13
16 14 52
3 10 80
14 11 85
15 2 77
4 11 19
2 7 49
10 7 78
14 6 84
13 7 50
11 6 75
5 10 46
13 8 43
9 10 49
7 12 64
0 10 76
5 9 77
8 3 28
11 9 28
12 16 87
12 6 24
9 15 94
5 7 77
4 10 18
7 2 11
9 5 41
13
4
13

Ans-47

2.

10
24
3 4 4
2 5 6
4 7 10
9 6 5
7 4 4
6 2 10
6 8 6
7 9 4
1 5 4
1 0 4
9 7 3
7 0 5
6 5 8
1 7 6
4 0 9
5 9 1
8 7 3
1 2 6
4 1 5
5 2 4
1 9 1
7 8 10
0 4 2
7 2 8
6
0
7

Ans-33


*/