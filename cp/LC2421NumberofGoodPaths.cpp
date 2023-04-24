#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int find(int x, vector<int> &parent)
{
    return x == parent[x] ? x : (parent[x] = find(parent[x], parent));
}

int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
{
    int n = vals.size();
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end(), [&](const vector<int> &x, const vector<int> &y)
         { return max(vals[x[0]], vals[x[1]]) < max(vals[y[0]], vals[y[1]]); });

    vector<int> cnt(n, 1);
    int ans = n;
    for (auto e : edges)
    {
        int x = e[0];
        int y = e[1];

        x = find(x, parent);
        y = find(y, parent);

        if (vals[x] == vals[y])
        {
            ans += (cnt[x] * cnt[y]);
            parent[x] = y;
            cnt[y] += cnt[x];
        }
        else if (vals[x] < vals[y])
        {
            parent[x] = y;
        }
        else
        {
            parent[y] = x;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vals(n);
    vector<vector<int>> edges;
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    cout << numberOfGoodPaths(vals, edges) << endl;

    return 0;
}