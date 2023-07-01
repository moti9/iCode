#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        int n = grid.size();
        int m = grid[0].length();

        int cntKeys = 0;
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                {
                    cntKeys += 1;
                }
                else if (grid[i][j] == '@')
                {
                    q.push({i, j, 0, 0});
                }
            }
        }

        int keys = pow(2, cntKeys) - 1;
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(keys + 1, 0)));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            int row = node[0], col = node[1], steps = node[2], currKeys = node[3];

            if (currKeys == keys)
            {
                return steps;
            }

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != '#')
                {
                    char curr = grid[nrow][ncol];

                    if (curr >= 'a' && curr <= 'f')
                    {
                        int newKeys = currKeys | (1 << (curr - 'a'));
                        if (vis[nrow][ncol][newKeys] == 0)
                        {
                            vis[nrow][ncol][newKeys] = 1;
                            q.push({nrow, ncol, steps + 1, newKeys});
                        }
                    }
                    else if (curr >= 'A' && curr <= 'F')
                    {
                        if (vis[nrow][ncol][currKeys] == 0 && (currKeys >> (curr - 'A')) & 1)
                        {
                            vis[nrow][ncol][currKeys] = 1;
                            q.push({nrow, ncol, steps + 1, currKeys});
                        }
                    }
                    else
                    {
                        if (vis[nrow][ncol][currKeys] == 0)
                        {
                            vis[nrow][ncol][currKeys] = 1;
                            q.push({nrow, ncol, steps + 1, currKeys});
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    Solution sol;
    cout << sol.shortestPathAllKeys(grid) << endl;

    return 0;
}