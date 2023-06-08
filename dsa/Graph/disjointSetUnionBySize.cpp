#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

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

    void unionBySize(int u, int v)
    {
        int ultpu = findUltParent(u);
        int ultpv = findUltParent(v);
        if (ultpu == ultpv)
        {
            return;
        }
        if (size[ultpu] < size[ultpv])
        {
            parent[ultpu] = ultpv;
            size[ultpv] += size[ultpu];
        }
        else
        {
            parent[ultpv] = ultpu;
            size[ultpu] += size[ultpv];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // check for (3, 7) belongs to same component or not
    if (ds.findUltParent(3) == ds.findUltParent(7))
    {
        cout << "Belongs to same component\n";
    }
    else
    {
        cout << "Not in the same component\n";
    }

    ds.unionBySize(3, 7);

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