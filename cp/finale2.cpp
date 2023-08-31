#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct Cell
{
    int row, col;
    int coins;
    int cntf;
};

int minimumCoins(vector<vector<char>> &matrix, int startRow, int startCol, int flags)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int minCoins = INT_MAX;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    vector<int> drow = {-1, 1, 0, 0};
    vector<int> dcol = {0, 0, -1, 1};

    queue<Cell> q;
    q.push({startRow, startCol, 0, 0});
    visited[startRow][startCol] = true;

    while (!q.empty())
    {
        Cell curr = q.front();
        q.pop();

        if (matrix[curr.row][curr.col] == 'F')
        {
            curr.cntf += 1;
            if (curr.cntf == flags)
            {
                minCoins = min(minCoins, curr.coins);
                continue;
            }
        }
        else if (matrix[curr.row][curr.col] == 'B')
        {
            curr.coins++;
        }

        for (int i = 0; i < 4; i++)
        {
            int newRow = curr.row + drow[i];
            int newCol = curr.col + dcol[i];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] != 'O' && !visited[newRow][newCol])
            {
                q.push({newRow, newCol, curr.coins, curr.cntf});
                visited[newRow][newCol] = true;
            }
        }
    }

    return minCoins;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int flags = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << matrix[i][j] << " ";
            flags += (matrix[i][j] == 'F');
        }
        // cout << endl;
    }

    // cout << flags << endl;

    int minCoins = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if (matrix[i][j] == 'O')
            //     continue;
            // else if (matrix[i][j] == 'F')
            // {
            int coins = minimumCoins(matrix, i, j, flags);
            minCoins = min(minCoins, coins);
            // }
        }
    }

    if (minCoins == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << minCoins << endl;
    }
    return 0;
}