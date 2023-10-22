#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    pair<int, int> searchIn2DMatrix(vector<vector<int>> &matrix, int n, int m, int x)
    {
        int row = 0, col = m - 1;
        while (row < n && col >= 0)
        {
            if (matrix[row][col] == x)
                return {row, col};
            else if (matrix[row][col] < x)
            {
                row += 1;
            }
            else
            {
                col -= 1;
            }
        }
        return {-1, -1};
    }
};

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
    int x;
    cin >> x;

    Solution sol;
    auto result = sol.searchIn2DMatrix(matrix, n, m, x);
    cout << result.first << " " << result.second << endl;

    return 0;
}