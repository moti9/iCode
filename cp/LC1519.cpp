#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(int node, int parent, vector<int> &ans, vector<int> &freq, vector<int> adj[], string label)
{
    int prevFreq = freq[label[node] - 'a'];
    freq[label[node] - 'a'] += 1;
    for (auto child : adj[node])
    {
        if (child == parent)
        {
            continue;
        }
        solve(child, node, ans, freq, adj, label);
    }
    ans[node] = freq[label[node] - 'a'] - prevFreq;
}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans(n), freq(26, 0);
    solve(0, -1, ans, freq, adj, labels);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    string label;
    cin >> label;

    vector<int> ans = countSubTrees(n, edges, label);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}