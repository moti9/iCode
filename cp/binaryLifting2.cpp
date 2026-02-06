#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

const int maxn = 1e5 + 5;
constexpr int maxe = 22; 
vector<vector<int>> adj;
int up[maxn][maxe];
int depth[maxn];
bool visited[maxn] = {false};

void dfs(int node, int parent, int depthVal) {
    up[node][0] = parent;
    visited[node] = true;
    depth[node] = depthVal;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, node, depthVal + 1);
        }
    }
}

int lift_node(int node, int k) {
    for (int l = 0; l < maxe; l++) {
        if (node != -1) {
            if (k & (1 << l)) {
                node = up[node][l];
            }
        }
    }
    return node;
}

int lca(int u, int v) {
    u = lift_node(u, depth[u] - min(depth[u], depth[v]));
    v = lift_node(v, depth[v] - min(depth[u], depth[v]));
    if (u == v) return u;
    for (int l = maxe - 1; l >= 0; l--) {
        if (up[u][l] != up[v][l]) {
            u = up[u][l];
            v = up[v][l];
        }
    }
    return up[u][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    adj.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(up, -1, sizeof(up));

    dfs(0, -1, 0);

    for(int l = 1; l < maxe; l++) {
        for(int i = 0; i < n; i++) {
            if(up[i][l-1] != -1) {
                up[i][l] = up[up[i][l-1]][l-1];
            }
        }
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int ancestor = lca(a, b);
        cout << ancestor + 1 << "\n";
    }

    

    return 0;
}