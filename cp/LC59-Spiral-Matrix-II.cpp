#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int floorMod(int x, int y)
    {
        return ((x % y) + y) % y;
    }

public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        int row = 0, col = 0;
        int val = 1;
        int dir = 0;
        int dirxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (val <= n * n)
        {
            matrix[row][col] = val++;
            int r = floorMod(row + dirxy[dir][0], n);
            int c = floorMod(col + dirxy[dir][1], n);
            if (matrix[r][c] != 0)
                dir = (dir + 1) % 4;
            row += dirxy[dir][0];
            col += dirxy[dir][1];
        }

        return matrix;
    }
};
/*
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        int val = 1;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                matrix[top][i] = val++;
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                matrix[i][right] = val++;
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    matrix[bottom][i] = val++;
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    matrix[i][left] = val++;
                }
                left++;
            }
        }
        return matrix;
    }
};
*/

int main()
{
    int n;
    cin >> n;
    Solution sol;
    vector<vector<int>> matrix = sol.generateMatrix(n);
    for (auto r : matrix)
    {
        for (auto c : r)
            cout << c << " ";
        cout << "\n";
    }
    return 0;
}