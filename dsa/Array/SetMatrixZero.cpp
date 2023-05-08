#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*M)
// SC- O(1)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        bool fcol = false;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
            {
                fcol = true;
            }
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >0; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
            if (fcol)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

// TC- O(N*M)
// SC- O(N+M)
/*
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> row(n, false), col(m, false);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};*/

// TC- O(N*M)
// SC- O(N*M)
/*
class Solution
{
    void solve(vector<vector<int>> &mat, int row, int col)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int j = 0; j < m; j++)
        {
            mat[row][j] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            mat[i][col] = 0;
        }
    }

public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans = matrix;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    solve(ans, i, j);
                }
            }
        }
        matrix = ans;
    }
};
*/

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
    sol.setZeroes(matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}