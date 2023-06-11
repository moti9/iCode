#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// nCr
// TC- O(M)
// SC- O(1)

class Solution
{
public:
    int uniquePaths(int n, int m)
    {
        int N = n + m - 2;
        int r = m - 1;
        double res = 1;
        for (int i = 1; i <= r; i++)
        {
            res = res * (N - r + i) / i;
        }
        return (int)res;
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