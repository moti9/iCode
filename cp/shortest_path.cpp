#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

int shortestPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // Ensure the grid is large enough to include the start and end points
    if (m < 1 || n < 1)
    {
        return -1;
    }

    int startX = 0, startY = 0;
    int endX = m - 1, endY = n - 1;

    if (grid[startX][startY] == 1 || grid[endX][endY] == 1)
    {
        return -1;
    }

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<pair<int, int>> q;
    q.push({startX, startY});
    vector<vector<int>> dist(m, vector<int>(n, -1));
    dist[startX][startY] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto &dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 0 && dist[newX][newY] == -1)
            {
                dist[newX][newY] = dist[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }

    return dist[endX][endY];
}

int main()
{
    vector<vector<int>> grid;
    string line;

    while (getline(cin, line))
    {
        vector<int> row;
        stringstream ss(line);
        int value;

        while (ss >> value)
        {
            row.push_back(value);
        }

        if (!row.empty())
        {
            grid.push_back(row);
        }
    }

    int result = shortestPath(grid);
    cout << result << "\n";

    return 0;
}
