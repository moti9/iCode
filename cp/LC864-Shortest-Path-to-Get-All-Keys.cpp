#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    struct QueueElement
    {
        int row;
        int col;
        unordered_map<int, int> keys;
        int moves;
    };

public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        int n = grid.size();
        int m = grid[0].length();

        int cntKeys = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z')
                {
                    cntKeys += 1;
                }
            }
        }

        if (cntKeys == 0)
        {
            return 0;
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        queue<QueueElement> q;
        QueueElement eleStart;
        eleStart.row = 0;
        eleStart.col = 0;
        eleStart.moves = 0;

        q.push(eleStart);

        while (!q.empty())
        {
            QueueElement node = q.front();
            q.pop();

            int row = node.row;
            int col = node.col;
            unordered_map<int, int> keys = node.keys;
            int moves = node.moves;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                {
                    continue;
                }
                else if (grid[nrow][ncol] == '#')
                {
                    continue;
                }
                if (grid[nrow][ncol] == '.')
                {
                    QueueElement nele;
                    nele.row = nrow;
                    nele.col = ncol;
                    nele.keys = keys;
                    nele.moves = moves + 1;
                    q.push(nele);
                }
                else if (grid[nrow][ncol] >= 'A' && grid[nrow][ncol] <= 'Z')
                {
                    int lock = grid[nrow][ncol] - 'A';
                    if (keys[lock] > 0)
                    {
                        keys[lock] -= 1;
                        QueueElement nele;
                        nele.row = nrow;
                        nele.col = ncol;
                        nele.keys = keys;
                        nele.moves = moves + 1;
                        q.push(nele);
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    cntKeys -= 1;
                    if (cntKeys == 0)
                    {
                        return moves + 1;
                    }
                    int key = grid[nrow][ncol] - 'a';
                    keys[key] += 1;
                    QueueElement nele;
                    nele.row = nrow;
                    nele.col = ncol;
                    nele.keys = keys;
                    nele.moves = moves + 1;
                    q.push(nele);
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