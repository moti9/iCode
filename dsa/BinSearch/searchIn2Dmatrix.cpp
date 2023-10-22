#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool searchIn2DMatrix(vector<vector<int>> &matrix, int n, int m, int x)
    {
        int low = 0, high = n * m - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == x)
                return true;
            else if (matrix[row][col] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
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
    cout << sol.searchIn2DMatrix(matrix, n, m, x) << endl;

    return 0;
}