#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool check(int i, int n, vector<vector<bool>> &mark)
    {
        for (int col = 1; col <= n; col++)
        {
            if (i != col && mark[i][col])
            {
                return false;
            }
            if (i != col && mark[col][i] == false)
            {
                return false;
            }
        }
        return true;
    }

public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<vector<bool>> mark(n + 1, vector<bool>(n + 1, 0));
        for (auto a : trust)
        {
            mark[a[0]][a[1]] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << mark[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
            if (check(i, n, mark))
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> trust;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        trust.push_back({a, b});
    }

    Solution sol;
    cout << sol.findJudge(n, trust) << endl;

    return 0;
}