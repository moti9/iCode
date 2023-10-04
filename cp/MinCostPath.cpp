#include <algorithm>
#include <vector>

using namespace std;

int minCostPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // Create a table to store the minimum cost path to reach each cell.
    vector<vector<int>> minCost(n, vector<int>(m, 1e9));

    // Initialize the base case.
    minCost[0][0] = matrix[0][0];

    // Iterate over the matrix and fill in the table.
    for (int i = 1; i < n; i++)
    {
        minCost[i][0] = min(minCost[i - 1][0], matrix[i][0]);
    }

    for (int j = 1; j < m; j++)
    {
        minCost[0][j] = min(minCost[0][j - 1], matrix[0][j]);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            minCost[i][j] = min(minCost[i - 1][j], min(minCost[i][j - 1], minCost[i - 1][j - 1])) + matrix[i][j];
        }
    }

    // Find the minimum cost path to reach the last column.
    int minCostPath = 1e9;
    for (int i = 0; i < n; i++)
    {
        minCostPath = min(minCostPath, minCost[i][m - 1]);
    }

    return minCostPath;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> matrix[j][k];
            }
        }

        int minCostPath = minCostPath(matrix);
        cout << minCostPath << endl;
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// const int INF = 1e9;

// int main()
// {
//     int T;
//     cin >> T;

//     while (T--)
//     {
//         int N, M;
//         cin >> N >> M;

//         vector<vector<int>> matrix(N, vector<int>(M));

//         for (int i = 0; i < N; ++i)
//         {
//             for (int j = 0; j < M; ++j)
//             {
//                 cin >> matrix[i][j];
//             }
//         }

//         vector<vector<int>> dp(N, vector<int>(M, INF));

//         for (int i = 0; i < N; ++i)
//         {
//             dp[i][0] = matrix[i][0];
//         }

//         for (int j = 1; j < M; ++j)
//         {
//             for (int i = 0; i < N; ++i)
//             {
//                 for (int k = 0; k < N; ++k)
//                 {
//                     dp[i][j] = min(dp[i][j], max(dp[k][j - 1], matrix[i][j]) - min(dp[k][j - 1], matrix[i][j]));
//                 }
//             }
//         }

//         int minCost = INF;
//         for (int i = 0; i < N; ++i)
//         {
//             minCost = min(minCost, dp[i][M - 1]);
//         }

//         cout << minCost << endl;
//     }

//     return 0;
// }
