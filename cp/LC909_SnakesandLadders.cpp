#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    vector<int> findCoordinate(int pos, int n)
    {
        int row = n - (pos - 1) / n - 1;
        int col = (pos - 1) % n;
        if (row % 2 == n % 2)
        {
            return {row, n - 1 - col};
        }
        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        int steps = 0;
        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool>(n));
        q.push(1);
        vis[n - 1][0] = true;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int curr = q.front();
                q.pop();
                if (curr == n * n)
                {
                    return steps;
                }
                for (int j = 1; j <= 6; j++)
                {
                    if (curr + j > n * n)
                    {
                        break;
                    }
                    vector<int> pos = findCoordinate(curr + j, n);
                    int row = pos[0];
                    int col = pos[1];
                    if (vis[row][col])
                        continue;
                    vis[row][col] = true;
                    if (board[row][col] == -1)
                    {
                        q.push(curr + j);
                    }
                    else
                    {
                        q.push(board[row][col]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    Solution sol;
    cout << sol.snakesAndLadders(board) << endl;

    return 0;
}