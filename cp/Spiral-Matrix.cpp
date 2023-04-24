#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> spiral;
    int n = matrix.size();
    int m = matrix[0].size();

    int rowst = 0, rowend = n - 1, colst = 0, colend = m - 1;
    while (rowst <= rowend && colst <= colend)
    {
        for (int i = colst; i <= colend; i++)
        {
            spiral.push_back(matrix[rowst][i]);
        }
        rowst++;

        for (int i = rowst; i <= rowend; i++)
        {
            spiral.push_back(matrix[i][colend]);
        }
        colend--;

        if (rowst <= rowend)
        {
            for (int i = colend; i >= colst; i--)
            {
                spiral.push_back(matrix[rowend][i]);
            }
        }
        rowend--;
        if (colst <= colend)
        {
            for (int i = rowend; i >= rowst; i--)
            {
                spiral.push_back(matrix[i][colst]);
            }
        }
        colst++;
    }
    return spiral;
}

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

    vector<int> spiral = spiralOrder(matrix);
    for (auto x : spiral)
        cout << x << " ";
    cout << endl;

    return 0;
}