#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class UnionFind
{
private:
    std::vector<int> parent;
    std::vector<int> rank;

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
            parent[x] = find(parent[x]); // Path compression
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

        // Union by rank
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
    long double density(int N, vector<int> par)
    {
        UnionFind uf(N);
        
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> par(n);
    for (int i = 0; i < n; i++)
    {
        cin >> par[i];
    }
    Solution sol;
    cout << sol.density(n, par) << endl;

    return 0;
}