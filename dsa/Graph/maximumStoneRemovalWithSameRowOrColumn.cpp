
#include <bits/stdc++.h>
using namespace std;

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

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        int maxRow = 0, maxCol = 0;
        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet dsu(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            dsu.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it : stoneNodes)
        {
            if (dsu.findUltParent(it.first) == it.first)
            {
                cnt += 1;
            }
        }
        return n - cnt;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int i = 0; i < 2; ++i)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
