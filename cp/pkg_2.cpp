#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void dfs(int u, int parent, int mask, vector<vector<int>> &adj, string &S, int &ans) {
    // flip the bit for current character
    int c = S[u-1] - 'a';
    mask ^= (1 << c);

    // check if path root->u is palindromic
    if (mask == 0 || (mask & (mask - 1)) == 0) ans++;

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u, mask, adj, S, ans);
    }
}

int solve(int N, vector<vector<int>> &E, string &S) {
    vector<vector<int>> adj(N+1);
    for (auto &e : E) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    dfs(1, -1, 0, adj, S, ans);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> E(N-1, vector<int>(2));
        for (int i = 0; i < N-1; i++) {
            cin >> E[i][0] >> E[i][1];
        }
        string S;
        cin >> S;

        cout << solve(N, E, S) << "\n";
    }
    return 0;
}





// #include <bits/stdc++.h>
// #include<iostream>
// using namespace std;

// int solve(int N, vector<vector<int>> &E, string &S) {
//     vector<vector<int>> adj(N+1);
//     for (auto &e : E) {
//         int u = e[0], v = e[1];
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     int ans = 0;

//     function<void(int,int,int)> dfs = [&](int u, int parent, int mask) {
//         // flip the bit for current character
//         int c = S[u-1] - 'a';
//         mask ^= (1 << c);

//         // check if path root->u is palindromic
//         if (mask == 0 || (mask & (mask-1)) == 0) ans++;

//         for (int v : adj[u]) {
//             if (v == parent) continue;
//             dfs(v, u, mask);
//         }
//     };

//     dfs(1, -1, 0);
//     return ans;
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int T;
//     cin >> T;
//     while (T--) {
//         int N;
//         cin >> N;
//         vector<vector<int>> E(N-1, vector<int>(2));
//         for (int i = 0; i < N-1; i++) {
//             cin >> E[i][0] >> E[i][1];
//         }
//         string S;
//         cin >> S;

//         cout << solve(N, E, S) << "\n";
//     }
//     return 0;
// }
