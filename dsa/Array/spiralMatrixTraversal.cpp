#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N)
// SC- O(N*N)
// Brute force

class Solution
{
public:
    void spiralTraversalMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        vector<int> ans;
        while (left <= right && top <= bottom)
        { // top-left--->top-right
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top += 1;
            // right-top--->right-bottom
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right -= 1;
            // bottom-right--->bottom-left
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom -= 1;
            }
            // left-bottom--->left-top
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left += 1;
            }
        }
        for (auto a : ans)
            cout << a << " ";
        cout << endl;
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
    sol.spiralTraversalMatrix(matrix);

    return 0;
}