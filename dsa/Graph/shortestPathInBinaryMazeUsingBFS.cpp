
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        int srow = source.first;
        int scol = source.second;
        int dstrow = destination.first;
        int dstcol = destination.second;
        if (srow == dstrow && scol == dstcol)
        {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[srow][scol] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {srow, scol}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int dst = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                {
                    continue;
                }
                else if (grid[nrow][ncol] == 0)
                {
                    continue;
                }
                if (dst + 1 < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = dst + 1;
                    if (nrow == dstrow && ncol == dstcol)
                    {
                        return dist[nrow][ncol];
                    }
                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return -1;
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
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}
