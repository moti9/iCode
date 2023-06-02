#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vect, int &row0, int &col0)
    {
        vis[row][col] = 1;
        vect.push_back({row - row0, col - col0});
        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < 0 || ncol < 0 || nrow >= grid.size() || ncol >= grid[0].size())
            {
                continue;
            }
            else if (vis[nrow][ncol] || !grid[nrow][ncol])
            {
                continue;
            }
            dfs(nrow, ncol, grid, vis, vect, row0, col0);
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vect;
                    dfs(i, j, grid, visited, vect, i, j);
                    st.insert(vect);
                }
            }
        }
        return st.size();
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    Solution sol;
    cout << sol.countDistinctIslands(grid) << endl;

    return 0;
}