#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    int minPathSum(int row, int col, vector<vector<int>> &triangle, int n)
    {
        if (row >= n)
        {
            return 1e9;
        }
        if (row == n - 1)
        {
            return triangle[row][col];
        }
        int down = triangle[row][col] + minPathSum(row + 1, col, triangle, n);
        int diag = triangle[row][col] + minPathSum(row + 1, col + 1, triangle, n);
        return min(down, diag);
    }

public:
    int minimumPathSum(vector<vector<int>> &triangle, int n)
    {
        return minPathSum(0, 0, triangle, n);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle;
    for (int i = 0; i < n; i++)
    {
        vector<int> row(i + 1);
        for (int j = 0; j <= i; j++)
        {
            cin >> row[j];
        }
        triangle.push_back(row);
    }

    Solution sol;
    cout << sol.minimumPathSum(triangle, n) << endl;

    return 0;
}