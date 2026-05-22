#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class UnionFind{
    public:
    vector<int> parent, size;
    int components;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findSet(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = findSet(parent[a]);
    }


    void unite(int a, int b) {
        int parentA = findSet(a);
        int parentB = findSet(b);
        if (parentA != parentB) {
            if (size[parentA] < size[parentB]) {
                swap(parentA, parentB);
            }
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
            components--;
        }
    }


    bool findAndUnite(int x, int y) {
        int parentX = findSet(x);
        int parentY = findSet(y);
        if (parentX != parentY) {
            unite(x, y);
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m * n);

        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char curr = grid[i][j];
                if (i > 0 && grid[i][j] == grid[i - 1][j]) {
                    if (!uf.findAndUnite(i * n + j, (i - 1) * n + j)) {
                        return true;
                    }
                }
                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
                    if (!uf.findAndUnite(i * n + j, i * n + j - 1)) {
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