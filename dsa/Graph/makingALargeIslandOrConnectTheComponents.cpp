
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size;

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
    int MaxConnection(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        DisjointSet dsu(n * n);
        // Step-1->DSU
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                {
                    continue;
                }
                for (int ind = 0; ind < 4; ind++)
                {
                    int nrow = row + drow[ind];
                    int ncol = col + dcol[ind];

                    if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n)
                    {
                        continue;
                    }
                    if (grid[nrow][ncol] == 1)
                    {
                        int node = row * n + col;
                        int adjNode = nrow * n + ncol;
                        dsu.unionBySize(node, adjNode);
                    }
                }
            }
        }

        // Step-2 -> try to convert 0 -> 1
        int maxCnt = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                {
                    continue;
                }
                unordered_set<int> components;
                for (int ind = 0; ind < 4; ind++)
                {
                    int nrow = row + drow[ind];
                    int ncol = col + dcol[ind];

                    if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n)
                    {
                        continue;
                    }
                    if (grid[nrow][ncol] == 1)
                    {
                        int adjNode = nrow * n + ncol;
                        components.insert(dsu.findUltParent(adjNode));
                    }
                }
                int sizeTotal = 1;
                for (auto comp : components)
                {
                    sizeTotal += dsu.size[comp];
                }
                maxCnt = max(maxCnt, sizeTotal);
            }
        }

        // If all are 1 ->size of ultimate parent of cells
        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {
            maxCnt = max(maxCnt, dsu.size[dsu.findUltParent(cellNo)]);
        }

        return maxCnt;
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
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}
