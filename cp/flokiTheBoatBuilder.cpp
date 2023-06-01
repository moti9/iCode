#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
        {
            return;
        }

        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

class Solution
{
public:
    int gcdTree(int n, vector<vector<int>> &edges, vector<int> &val, int x, int y)
    {
        vector<unordered_set<int>> graph(n);
        UnionFind uf(n);

        // Build the graph and perform unions based on the given edges
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].insert(v);
            graph[v].insert(u);

            uf.unite(u, v);
        }

        // Check if x and y have a common ancestor
        if (uf.find(x) != uf.find(y))
        {
            return -1; // x and y are not in the same tree
        }

        int gcd = computeGCD(val, x, y, graph, uf);

        return gcd;
    }

private:
    int computeGCD(const vector<int> &val, int x, int y, const vector<unordered_set<int>> &graph, UnionFind &uf)
    {
        int gcd = 0;

        // Traverse the path from x to the root and compute the gcd
        while (x != uf.find(x))
        {
            int parent = uf.find(x);
            int exclude = x;

            for (int child : graph[parent])
            {
                if (child == exclude)
                {
                    continue;
                }

                gcd = __gcd(gcd, val[child]);
            }

            x = parent;
        }

        // Traverse the path from y to the root and compute the gcd
        while (y != uf.find(y))
        {
            int parent = uf.find(y);
            int exclude = y;

            for (int child : graph[parent])
            {
                if (child == exclude)
                {
                    continue;
                }

                gcd = __gcd(gcd, val[child]);
            }

            y = parent;
        }

        return gcd;
    }
};

int main()
{

    return 0;
}




// class Solution
// {
// public:
//     int gcdTree(int n, vector<vector<int>> &edges, vector<int> &val, int x, int y)
//     {
//         vector<unordered_set<int>> graph(n);
//         UnionFind uf(n);

//         for (const auto &edge : edges)
//         {
//             int u = edge[0];
//             int v = edge[1];

//             graph[u].insert(v);
//             graph[v].insert(u);

//             uf.unite(u, v);
//         }

//         int gcd = val[x];
//         if (uf.find(x) != uf.find(y))
//         {
//             return -1;
//         }

//         while (x != uf.find(x))
//         {
//             x = uf.find(x);
//             gcd = __gcd(gcd, val[x]);
//         }

//         while (y != uf.find(y))
//         {
//             y = uf.find(y);
//             gcd = __gcd(gcd, val[y]);
//         }

//         return gcd;
//     }
// };