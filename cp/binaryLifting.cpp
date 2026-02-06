#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007


void dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited, vector<vector<int>> &up) {
    up[node][0] = parent;
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, node, adj, visited, up);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int mxn = n + 5;
    int mxe = log2(mxn) + 5;

    vector<bool> visited(n, false);
    vector<vector<int>> up(mxn, vector<int>(mxe, -1));

    dfs(0, -1, adj, visited, up);

    for(int l = 1; l < mxe; l++) {
        for(int i = 0; i < n; i++) {
            if(up[i][l-1] != -1) {
                up[i][l] = up[up[i][l-1]][l-1];
            }
        }
    }

    for(int i = 0; i < q; i++) {
        int node, k;
        cin >> node >> k;
        node--;

        for(int l = 0; l < mxe; l++) {
            if(k & (1 << l)) {
                node = up[node][l];
                if(node == -1) break;
            }
        }

        cout << node + 1 << "\n";
    }


    return 0;
}