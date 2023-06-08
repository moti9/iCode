#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent;

    DisjointSet(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltParent(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = findUltParent(parent[u]);
        }
        return parent[u];
    }

    void unionByRank(int u, int v)
    {
        int ultpu = findUltParent(u);
        int ultpv = findUltParent(v);
        if (rank[ultpu] < rank[ultpv])
        {
            parent[ultpu] = ultpv;
        }
        else if (rank[ultpv] < rank[ultpu])
        {
            parent[ultpv] = ultpu;
        }
        else
        {
            parent[ultpv] = ultpu;
            rank[ultpu] += 1;
        }
    }
};

class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge)
    {
        DisjointSet ds(n);
        int extraedges = 0;
        for (auto e : edge)
        {
            if (ds.findUltParent(e[0]) != ds.findUltParent(e[1]))
            {
                ds.unionByRank(e[0], e[1]);
            }
            else
            {
                extraedges += 1;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            ds.findUltParent(i) == i ? cnt += 1 : cnt += 0;
        }
        return extraedges >= (cnt - 1) ? cnt - 1 : -1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
