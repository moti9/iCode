#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
void solve(int node, int pr, int &ans, vector<int> &cnt, vector<int> adj[], string &s)
{
    for (auto child : adj[node])
    {
        if (child == node)
        {
            continue;
        }
        solve(child, node, ans, cnt, adj, s);
        if (s[child] != s[node])
        {
            ans = max(ans, cnt[node] + cnt[child]);
            cnt[node] = max(cnt[node], cnt[child] + 1);
        }
    }
}

void solve(int node, int pr, int &ans, vector<int> &cnt, vector<int> adj[], string &s)
{
    cnt[node] = 1;
    for (auto child : adj[node])
    {
        if (child == node)
        {
            continue;
        }
        solve(child, node, ans, cnt, adj, s);
        if (s[child] != s[node])
        {
            ans = max(ans, cnt[node] + cnt[child]);
            cnt[node] = max(cnt[node], cnt[child] + 1);
        }
    }
}

int longestPath(vector<int> &parent, string s)
{
    if (parent[0] != -1)
    {
        return -1;
    }
    int n = parent.size();
    vector<int> adj[n];
    for (int i = 1; i < n; i++)
    {
        adj[parent[i]].push_back(i);
        adj[i].push_back(parent[i]);
    }
    int ans = 1;
    vector<int> cnt(n);
    solve(0, 0, ans, cnt, adj, s);
    return ans;
}
*/

void solve(int node, int &ans, vector<int> &cnt, vector<vector<int>> &adj, string &s)
{
    cnt[node] = 1;
    for (auto child : adj[node])
    {
        solve(child, ans, cnt, adj, s);
        if (s[child] != s[node])
        {
            ans = max(ans, cnt[node] + cnt[child]);
            cnt[node] = max(cnt[node], cnt[child] + 1);
        }
    }
}

int longestPath(vector<int> &parent, string s)
{
    if (parent[0] != -1)
    {
        return -1;
    }
    int n = parent.size();
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        adj[parent[i]].push_back(i);
        // adj[i].push_back(parent[i]);
    }
    int ans = 1;
    vector<int> cnt(n);
    solve(0, ans, cnt, adj, s);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
    }
    string s;
    cin >> s;

    cout << longestPath(parent, s) << endl;

    return 0;
}