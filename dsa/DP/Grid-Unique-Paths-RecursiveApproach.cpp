#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N*M)
// SC- O(pathLen) -> O(M+N-2)

/*
    In problem stated we can move only right and down(from top to bottom),
    as we are moving top to bottom so we'll move up and left(reverse)
*/

class Solution
{
    int countPaths(int row, int col)
    {
        if (row == 0 && col == 0)
        {
            return 1;
        }
        if (row < 0 || col < 0)
        {
            return 0;
        }
        int up = countPaths(row - 1, col);
        int left = countPaths(row, col - 1);

        return up + left;
    }

public:
    int uniquePaths(int n, int m)
    {
        return countPaths(n - 1, m - 1);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    Solution sol;
    cout << sol.uniquePaths(n, m);

    return 0;
}