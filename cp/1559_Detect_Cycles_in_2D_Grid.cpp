#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution {
    int m, n;
    vector<vector<int>> visited;
    vector<vector<char>> grid;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool dfs(int x, int y, int fromX, int fromY, char target) {
        if (visited[x][y]) {
            return true;
        }
        visited[x][y] = 1;

        for (auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == target) {
                if (!(newX == fromX && newY == fromY)) {
                    if (dfs(newX, newY, x, y, target)) {
                        return true;
                    }
                } else if (newX != fromX || newY != fromY) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));
        this->grid = grid;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    bool result = sol.containsCycle(grid);
    cout << (result ? "true" : "false") << endl;

    return 0;
}