#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, -1, 0, 1};

class Solution
{

    bool findPath(vector<vector<int>> &grid, int &n, int &m)
    {
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 0 && visited[0][j] == 0)
            {
                q.push({0, j});
                visited[0][j] = 1;

                while (!q.empty())
                {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();

                    if (row == n - 1)
                    {
                        return true;
                    }

                    // Explore neighbors
                    for (int i = 0; i < 4; i++)
                    {
                        int nrow = row + drow[i];
                        int ncol = col + dcol[i];
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && visited[nrow][ncol] == 0)
                        {
                            visited[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        vector<vector<int>> grid(row, vector<int>(col, 0));

        int n = cells.size();

        for (int day = 0; day < n; day++)
        {
            int r = cells[day][0];
            int c = cells[day][1];

            grid[r - 1][c - 1] = 1;
        }

        if (findPath(grid, row, col) == true)
        {
            return n;
        }

        for (int day = n - 1; day >= 0; day--)
        {
            int r = cells[day][0];
            int c = cells[day][1];

            grid[r - 1][c - 1] = 0;

            if (findPath(grid, row, col) == true)
            {
                return day;
            }
        }
        return 0;
    }
};

int main()
{
    int row, col;
    cin >> row >> col;

    int n;
    cin >> n;
    vector<vector<int>> cells;
    for (int i = 0; i < n; i++)
    {
        int r, c;
        cin >> r >> c;
        cells.push_back({r, c});
    }

    Solution sol;
    cout << sol.latestDayToCross(row, col, cells);

    return 0;
}