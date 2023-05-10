#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(4*N*N)
// SC- O(1)

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int topleft = 0, topright = m - 1, bottomright = n - 1, bottomleft = 0;

        while (topleft < topright && bottomleft < bottomright)
        {
            int temp = matrix[topleft][bottomleft];

            // Move elements of left column to top row
            for (int i = topleft + 1; i <= bottomright; i++)
            {
                matrix[i - 1][bottomleft] = matrix[i][bottomleft];
            }

            // Move elements of bottom row to left column
            for (int i = bottomleft + 1; i <= topright; i++)
            {
                matrix[bottomright][i - 1] = matrix[bottomright][i];
            }

            // Move elements of right column to bottom row
            for (int i = bottomright - 1; i >= topleft; i--)
            {
                matrix[i + 1][topright] = matrix[i][topright];
            }

            // Move elements of top row to right column
            for (int i = topright - 1; i >= bottomleft; i--)
            {
                matrix[topleft][i + 1] = matrix[topleft][i];
            }

            // Put the top-left element in its new position
            matrix[topleft][bottomleft + 1] = temp;

            // Move to the next layer
            topleft++;
            bottomleft++;
            topright--;
            bottomright--;
        }
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
    sol.rotate(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }

    return 0;
}