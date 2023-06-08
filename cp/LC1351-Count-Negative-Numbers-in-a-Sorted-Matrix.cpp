#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using Linear Traversal
// TC- O(N+M)
// SC- O(1)

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        int n = grid[0].size();
        int currIndex = n - 1;
        for (auto &row : grid)
        {
            while (currIndex >= 0 && row[currIndex] < 0)
            {
                currIndex -= 1;
            }
            count += (n - currIndex - 1);
        }
        return count;
    }
};

// Using Binary Search
// TC- O(NlogM)
// SC- O(1)
/*
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        int n = grid.size();
        for (auto &row : grid)
        {
            int index = upper_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin();
            count += (n - index);
        }
        return count;
    }
};
*/

// Brute Force
// TC-O(N*M)
// SC-O(1)
/*
class Solution
{)
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        for (auto &row : grid)
        {
            for (auto &element : row)
            {
                if (element < 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
*/

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.countNegatives(grid) << endl;

    return 0;
}