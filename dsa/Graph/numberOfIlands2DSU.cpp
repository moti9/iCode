
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        DisjointSet dsu(n * m);
        vector<vector<int>> islands(n, vector<int>(m));

        int cnt = 0;
        vector<int> ans;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if (islands[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            islands[row][col] = 1;
            cnt += 1;
            // 4-directions
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                // check validity
                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                {
                    continue;
                }
                // Islands -> connect
                if (islands[nrow][ncol] == 1)
                {
                    int node = row * m + col;
                    int adjNode = nrow * m + ncol;
                    if (dsu.findUltParent(node) != dsu.findUltParent(adjNode))
                    {
                        cnt -= 1;
                        dsu.unionBySize(node, adjNode);
                    }
                }
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a;

        for (int i = 0; i < k; i++)
        {
            vector<int> temp;
            for (int j = 0; j < 2; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.numOfIslands(n, m, a);

        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
}
