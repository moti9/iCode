#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N)
// SC- O(1)

class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = 0;
        int prev, curr;
        int lastRow = n;
        int lastCol = m;
        while (row < lastRow && col < lastCol)

        {
            if (row + 1 == lastRow || col + 1 == lastCol)
                break;

            prev = matrix[row + 1][col];
            // for the first row which is in bounds
            for (int i = col; i < lastCol; i++)
            {
                curr = matrix[row][i];
                matrix[row][i] = prev;
                prev = curr;
            }
            row++;
            // for the last column which is in bounds
            for (int i = row; i < lastRow; i++)
            {
                curr = matrix[i][lastCol - 1];
                matrix[i][lastCol - 1] = prev;
                prev = curr;
            }
            lastCol--;
            // for the last row which is in bounds
            if (row < lastRow)
            {
                for (int i = lastCol - 1; i >= col; i--)
                {
                    curr = matrix[lastRow - 1][i];
                    matrix[lastRow - 1][i] = prev;
                    prev = curr;
                }
            }
            lastRow--;
            // for the first row which is in bounds
            if (col < lastCol)
            {
                for (int i = lastRow - 1; i >= row; i--)
                {
                    curr = matrix[i][col];
                    matrix[i][col] = prev;
                    prev = curr;
                }
            }
            col++;
        }
    }
};
// class Solution
// {
// public:
//     void rotateMatrix(vector<vector<int>> &matrix)
//     {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         int top = 0, bottom = n - 1;
//         int left = 0, right = m - 1;
//         int curr, prev;

//         while (left <= right && top <= bottom)
//         {
//             if (left + 1 > right || top + 1 > bottom)
//                 break;
//             prev = matrix[left + 1][top];
//             for (int i = top; i <= bottom; i++)
//             {
//                 curr = matrix[left][i];
//                 matrix[left][i] = prev;
//                 prev = curr;
//             }
//             left += 1;

//             for (int i = left; i <= right; i++)
//             {
//                 curr = matrix[i][bottom];
//                 matrix[i][bottom] = prev;
//                 prev = curr;
//             }
//             bottom -= 1;

//             if (left <= right)
//             {
//                 for (int i = bottom; i >= top; i--)
//                 {
//                     curr = matrix[right][i];
//                     matrix[right][i] = prev;
//                     prev = curr;
//                 }
//             }
//             right -= 1;

//             if (top <= bottom)
//             {
//                 for (int i = right; i >= left; i--)
//                 {
//                     curr = matrix[i][top];
//                     matrix[i][top] = prev;
//                     prev = curr;
//                 }
//             }
//             top += 1;
//         }
//     }
// };

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    sol.rotateMatrix(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }

    return 0;
}