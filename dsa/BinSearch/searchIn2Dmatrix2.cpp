#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    pair<int, int> searchIn2DMatrix(vector<vector<int>> &matrix, int n, int m, int x)
    {
        for (int row = 0; row < n; row++)
        {
            int low = 0, high = m - 1;
            while (low <= high)
            {
                int mid = (low + high) >> 1;
                if (matrix[row][mid] == x)
                    return {row, mid};
                else if (matrix[row][mid] < x)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
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