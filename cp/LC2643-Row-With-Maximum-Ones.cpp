#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int ind = -1, cnt = -1;
        int i = 0;
        for (auto arr : mat)
        {
            int ct = count(arr.begin(), arr.end(), 1);
            if (ct > cnt)
            {
                cnt = ct;
                ind = i;
            }
            i += 1;
        }
        return {ind, cnt};
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    Solution sol;
    auto ans = sol.rowAndMaximumOnes(mat);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}