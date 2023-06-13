#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N)
// SC- O(N)

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int cnt = 0;
        for (int row = 0; row < n; row++)
        {
            vector<int> colArr;
            for (int col = 0; col < n; col++)
            {
                colArr.push_back(grid[col][row]);
            }
            for (int i = 0; i < n; i++)
            {
                if (colArr == grid[i])
                {
                    cnt += 1;
                }
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