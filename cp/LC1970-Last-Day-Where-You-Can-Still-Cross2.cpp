#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        int n = cells.size();

        for (int day = 0; day < n; day++)
        {
            int r = cells[day][0];
            int c = cells[day][1];

            grid[r - 1][c - 1] = 1;
        }

        queue<pair<int, int>> q;

        for (int day = n - 1; day >= 0; day--)
        {
            int r = cells[day][0];
            int c = cells[day][1];

            grid[r - 1][c - 1] = 0;

            vector<vector<int>> visited(row, vector<int>(col, 0));
            for (int j = 0; j < col; j++)
            {
                if (grid[0][j] == 0 && visited[0][j] == 0)
                {
                    q.push({0, j});
                    visited[0][j] = 1;

                    while (!q.empty())
                    {
                        int curRow = q.front().first;
                        int curCol = q.front().second;
                        q.pop();

                        if (curRow == row - 1)
                        {
                            return day;
                        }

                        for (int i = 0; i < 4; i++)
                        {
                            int nextRow = curRow + drow[i];
                            int nextCol = curCol + dcol[i];
                            if (nextRow >= 0 && nextRow < row && nextCol >= 0 && nextCol < col && grid[nextRow][nextCol] == 0 && visited[nextRow][nextCol] == 0)
                            {
                                visited[nextRow][nextCol] = 1;
                                q.push({nextRow, nextCol});
                            }
                        }
                    }
                }
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