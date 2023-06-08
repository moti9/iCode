#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class DisjointSet
{
    vector<int> rank, parent;

public:
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
    int numProvinces(vector<vector<int>> adj, int V)
    {
        DisjointSet ds(V);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1)
                {
                    ds.unionByRank(i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (ds.findUltParent(i) == i)
            {
                cnt += 1;
            }
        }
        return cnt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
