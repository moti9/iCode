#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using Union-Find
// TC- O(N*N)
// SC- O(N)+O(N)

class UnionFind
{

    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n);
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

    void unionSet(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[yset] < rank[yset])
        {
            parent[yset] = xset;
        }
        else
        {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        UnionFind unf(n);
        int cnt = n;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] && unf.find(i) != unf.find(j))
                {
                    cnt -= 1;
                    unf.unionSet(i, j);
                }
            }
        }

        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> isConnected[i][j];
        }
    }
    Solution sol;
    cout << sol.findCircleNum(isConnected) << endl;
    return 0;
}