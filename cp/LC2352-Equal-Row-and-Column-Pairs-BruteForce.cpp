#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N*N)
// SC- O(1)

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int cnt = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                bool isEqual = true;
                for (int i = 0; i < n; i++)
                {
                    if (grid[i][col] != grid[row][i])
                    {
                        isEqual = false;
                        break;
                    }
                }
                cnt += isEqual;
            }
        }
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.equalPairs(grid) << endl;

    return 0;
}