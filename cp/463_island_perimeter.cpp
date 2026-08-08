#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution
{
    vector<pair<int, int>> paths = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
    int calculateIslandPerimeter(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        int per = 0;
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            pair<int, int> cord = q.front();
            q.pop();

            for (int ix = 0; ix < 4; ix++)
            {
                int in = cord.first + paths[ix].first;
                int jn = cord.second + paths[ix].second;

                if ((in < 0 || in >= n || jn < 0 || jn >= m) || grid[in][jn] == 0)
                {
                    per += 1;
                }
                else if (!vis[in][jn])
                {
                    q.push({in, jn});
                    vis[in][jn] = true;
                }
            }
        }

        return per;
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    ans += calculateIslandPerimeter(i, j, n, m, grid, visited);
                }
            }
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << Solution().islandPerimeter(grid) << endl;

    return 0;
}