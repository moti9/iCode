#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Variation 1: (Find the element at position (r,c))

// TC- O(c)
// SC- O(1)
int nCr(int n, int r)
{
    int ans = 1;
    for (int i = 0; i < (int)r; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
    return ans;
}
void pascalTriangleElement(int r, int c)
{
    int element = nCr(r - 1, c - 1);
    cout << element << endl;
}

// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// Naive Approach :
// TC- O(N*C)
// SC- O(1)
void pascalTriangleRow(int n)
{
    for (int c = 1; c <= n; c++)
    {
        int element = nCr(n - 1, c - 1);
        cout << element << " ";
    }
    cout << endl;
}
// Optimal Approach :
// TC- O(N)
// SC- O(1)
void pascalTriangleRowop(int n)
{
    int ans = 1;
    cout << ans << " ";
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i);
        cout << ans << " ";
    }
    cout << endl;
}

// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
// Variation 1 + Variation 2

// TC- O(N*N)
// SC- O(N*N)
vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    // calculate the rest of the elements:
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

void pascalTriangle(int n)
{
    vector<vector<int>> ans;

    // store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    for (auto r : ans)
    {
        for (auto c : r)
            cout << c << " ";
        cout << "\n";
    }
}

// TC- O(N*M)
// SC- O(N*M)
void generate_pascal(int n)
{
    vector<vector<int>> pascal(n);
    for (int i = 0; i < n; i++)
    {
        pascal[i].resize(i + 1);
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
        }
    }
    for (auto p : pascal)
    {
        for (auto x : p)
            cout << x << " ";
        cout << "\n";
    }
}

int main()
{
    int n, r;
    // cin >> n >> r;
    // cout << nCr(n - 1, r - 1) << endl;
    // pascalTriangleElement(n - 1, r - 1);
    cin >> n;
    // pascalTriangleRow(n);
    // pascalTriangleRowop(n);
    pascalTriangle(n);
    generate_pascal(n);

    return 0;
}