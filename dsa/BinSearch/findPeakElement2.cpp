#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findMaxIndex(vector<vector<int>> &mat, int n, int col)
    {
        int maxi = 0, maxInd = -1;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][col] > maxi)
            {
                maxi = mat[i][col];
                maxInd = i;
            }
        }
        return maxInd;
    }

public:
    pair<int, int> findPeak(vector<vector<int>> &matrix, int n, int m)
    {
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int row = findMaxIndex(matrix, n, mid);
            int left = (mid - 1 >= 0) ? matrix[row][mid - 1] : -1;
            int right = (mid + 1 < n) ? matrix[row][mid + 1] : -1;
            if (matrix[row][mid] > left && matrix[row][mid] > right)
                return {row, mid};
            else if (matrix[row][mid] < left)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
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

    Solution sol;
    auto result = sol.findPeak(matrix, n, m);
    cout << result.first << " " << result.second << endl;

    return 0;
}