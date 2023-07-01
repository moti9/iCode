#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool isPath(int n, int m, vector<vector<int>> &cells, int day)
    {
        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (int i = 0; i < day; i++)
        {
            int r = cells[i][0];
            int c = cells[i][1];
            grid[r - 1][c - 1] = 1;
        }

        queue<vector<int>> q;
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 0)
            {
                q.push({0, j});
                grid[0][j] = -1;
            }
        }

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int row = curr[0];
            int col = curr[1];

            if (row == n - 1)
            {
                return true;
            }

            for (auto &dirs : directions)
            {
                int nrow = row + dirs.first;
                int ncol = col + dirs.second;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0)
                {
                    grid[nrow][ncol] = -1;
                    q.push({nrow, ncol});
                }
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int left = 1;
        int right = row * col;

        while (left < right)
        {
            int mid = right - (right - left) / 2;
            if (isPath(row, col, cells, mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};

int main()
{
    int row, col;
    cin >> row >> col;

    int days;
    cin >> days;
    vector<vector<int>> cells;
    for (int i = 0; i < days; i++)
    {
        int r, c;
        cin >> r >> c;
        cells.push_back({r, c});
    }

    Solution sol;
    cout << sol.latestDayToCross(row, col, cells);

    return 0;
}