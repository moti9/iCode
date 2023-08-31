// int findMinimumCoins(int n, int m, vector<vector<char>> &matrix)
// {
//     queue<Cell> q;
//     vector<vector<bool>> visited(n, vector<bool>(m));
//     vector<vector<int>> coinMat(n, vector<int>(m, 1e7));

//     int flags = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == 'F')
//             {
//                 q.push({i, j, 0});
//                 visited[i][j] = true;
//                 flags += 1;
//             }
//         }
//     }

//     while (!q.empty())
//     {
//         Cell current = q.front();
//         q.pop();

//         int row = current.row;
//         int col = current.col;
//         int coins = current.coins;

//         if (matrix[row][col] == 'B')
//         {
//             coinMat[row][col] = coins;
//         }

//         int drow[] = {-1, 0, 1, 0};
//         int dcol[] = {0, 1, 0, -1};

//         for (int i = 0; i < 4; i++)
//         {
//             int nrow = row + drow[i];
//             int ncol = col + dcol[i];

//             if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] != 'O' && !visited[nrow][ncol])
//             {    
//                 visited[nrow][ncol] = true;
//                 q.push({nrow, ncol, coins + 1});
//             }
//         }
//     }

//     int minCoins = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == 'B' && coinMat[i][j] < minCoins)
//             {
//                 minCoins = coinMat[i][j];
//             }
//         }
//     }

//     if (minCoins >= 1e7)
//         return -1;

//     return minCoins;
// }