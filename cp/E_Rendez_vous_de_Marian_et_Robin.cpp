#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void dijkstra(ll src, vector<vector<ll>> &dist, unordered_map<ll, unordered_map<ll, ll>> &graph, unordered_map<ll, ll> &horse)
{
    dist[src][0] = 0;

    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    pq.push({0, {src, 0}});

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        ll isHorse = node.second.second || horse[node.second.first];

        for (auto &nb : graph[node.second.first])
        {
            ll dst = (isHorse) ? nb.second / 2 : nb.second;

            if (dist[nb.first][isHorse] > dist[node.second.first][node.second.second] + dst)
            {
                dist[nb.first][isHorse] = dist[node.second.first][node.second.second] + dst;
                pq.push({dist[nb.first][isHorse], {nb.first, isHorse}});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        ll n, m, h;
        cin >> n >> m >> h;

        unordered_map<ll, ll> horse;
        for (ll i = 0; i < h; i++)
        {
            ll a;
            cin >> a;
            horse[a]++;
        }

        unordered_map<ll, unordered_map<ll, ll>> graph;
        for (ll i = 0; i < m; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        vector<vector<ll>> dists(n + 1, vector<ll>(2, LLONG_MAX));
        vector<vector<ll>> diste(n + 1, vector<ll>(2, LLONG_MAX));

        dijkstra(1, dists, graph, horse);

        dijkstra(n, diste, graph, horse);

        ll ans = 0;

        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, min({dists[i][0], dists[i][1], diste[i][0], diste[i][1]}));
        }

        cout << ((ans == LLONG_MAX) ? -1 : ans) << "\n";
    }

    return 0;
}

/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/