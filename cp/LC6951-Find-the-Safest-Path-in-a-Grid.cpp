#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

#include <vector>
#include <queue>
#include <climits>

class Solution
{
public:
    struct Node
    {
        int row, col, dist;
        Node(int r, int c, int d) : row(r), col(c), dist(d) {}
    };

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return 0;
        vector<pair<int, int>> thief;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    thief.push_back({i, j});
            }
        }
        vector<vector<int>> distance(n, vector<int>(n, 1e5));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int dist = 1e5;
                if (grid[i][j] == 0)
                {
                    for (auto &x : thief)
                    {
                        int a = abs(i - x.first);
                        int b = abs(j - x.second);
                        dist = min(dist, a + b);
                    }
                }
                distance[i][j] = dist;
            }
        }

        queue<Node> q;
        grid[0][0] = -1;
        q.push(Node(0, 0, distance[0][0]));

        int maxDist = 0;

        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};

        while (!q.empty())
        {

            Node current = q.front();
            q.pop();

            int r = current.row;
            int c = current.col;
            int dist = current.dist;

            if (r == n - 1 && c == n - 1)
            {
                maxDist = max(maxDist, dist);
                continue;
            }

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n)
                {
                    if (grid[nr][nc] == 0 && distance[nr][nc] > dist + 1)
                    {
                        grid[nr][nc] = -1;
                        distance[nr][nc] = abs(nr - r) + abs(nc - c);
                        q.push(Node(nr, nc, distance[nr][nc]));
                    }
                    else if (grid[nr][nc] == -1)
                    {
                        grid[nr][nc] = dist + distance[nr][nc];
                    }
                }
            }
        }

        return maxDist;
    }
};

int main()
{

    return 0;
}