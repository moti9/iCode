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

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // check for (3, 7) belongs to same component or not
    if (ds.findUltParent(3) == ds.findUltParent(7))
    {
        cout << "Belongs to same component\n";
    }
    else
    {
        cout << "Not in the same component\n";
    }

    ds.unionByRank(3, 7);
    
    // check for (3, 7) belongs to same component or not
    if (ds.findUltParent(3) == ds.findUltParent(7))
    {
        cout << "Belongs to same component\n";
    }
    else
    {
        cout << "Not in the same component\n";
    }

    return 0;
}