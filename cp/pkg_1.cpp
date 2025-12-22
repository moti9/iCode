#include <bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> solve(int N, int M, vector<pair<int,int>>& edges) {
    vector<vector<int>> adj(N+1);
    vector<int> indeg(N+1, 0);

    for(auto &e : edges) {
        adj[e.first].push_back(e.second);
        indeg[e.second]++;
    }

    // Min-heap for lexicographically smallest order
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1; i<=N; i++) {
        if(indeg[i] == 0) pq.push(i);
    }

    vector<int> result;
    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();
        result.push_back(u);

        for(int v : adj[u]) {
            indeg[v]--;
            if(indeg[v] == 0) pq.push(v);
        }
    }

    if((int)result.size() < N) return {-1}; // cycle
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, M;
        cin >> N >> M;
        vector<pair<int,int>> order(M);
        for(int i=0; i<M; i++) {
            cin >> order[i].first >> order[i].second;
        }

        vector<int> ans = solve(N, M, order);
        if(ans.size() == 1 && ans[0] == -1) {
            cout << -1 << "\n";
        } else {
            for(int i=0; i<ans.size(); i++) {
                if(i > 0) cout << " ";
                cout << ans[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
