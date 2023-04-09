#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<bool>> &vis)
    {
        vis[row][col] = true;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < 0 || nrow >= board.size() || ncol < 0 || ncol >= board[0].size())
            {
                continue;
            }
            else if (!vis[nrow][ncol] && board[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, board, vis);
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, board, vis);
        }
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, board, vis);
            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, board, vis);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};

int main()
{

    return 0;
}