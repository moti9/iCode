#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Effieicnt Binary Search--0 to (m*n)-1
//  TC O(log(N*M))
//  SC- O(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = n * m - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[mid / m][mid % m] == target)
                return true;
            else if (matrix[mid / m][mid % m] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }
};

// TC- O(N)
// SC- O(1)
// Binary Search
/*
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] <= target && target <= matrix[i][matrix[0].size() - 1])
            {
                return binary_search(matrix[i].begin(), matrix[i].end(), target);
            }
        }
        return false;
    }
};
*/

// TC- O(NlogM)
// SC- O(1)
// Naive Approach
/*
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (binary_search(matrix[i].begin(), matrix[i].end(), target))
            {
                return true;
            }
        }
        return false;
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
    int target;
    cin >> target;
    Solution sol;
    cout << sol.searchMatrix(matrix, target) << endl;

    return 0;
}