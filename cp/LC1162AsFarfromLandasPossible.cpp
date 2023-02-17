#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return -1;

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }

        if (q.empty() || q.size() == n * n)
            return -1;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto t = q.front();
                q.pop();
                int x = t.first, y = t.second;
                for (auto dir : dirs)
                {
                    int a = x + dir[0], b = y + dir[1];
                    if (a >= 0 && a < n && b >= 0 && b < n && grid[a][b] == 0)
                    {
                        grid[a][b] = grid[x][y] + 1;
                        q.push({a, b});
                        res = max(res, grid[a][b] - 1);
                    }
                }
            }
        }

        if (res == 0)
            return -1;
        return res;
    }
};

int main()
{
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
    Solution sol;
    cout << sol.maxDistance(grid) << endl;

    return 0;
}