#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool check(int len, vector<vector<int>> &mat, int n, int m)
    {
        for (int i = 0; i <= n - len; i++)
        {
            for (int j = 0; j <= m - len; j++)
            {
                bool valid = true;
                for (int k = i; k < i + len; k++)
                {
                    for (int l = j; l < j + len; l++)
                    {
                        if (mat[k][l] < len)
                        {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid)
                    {
                        break;
                    }
                }

                if (valid)
                {
                    return true;
                }
            }
        }

        return false;
    }

public:
    int maxGoodLength(vector<vector<int>> &a)
    {
        int n = a.size();
        int m = a[0].size();
        int left = 1, right = min(n, m);
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(mid, a, n, m))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, i, j;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        Solution ob;
        int ans = ob.maxGoodLength(a);
        cout << ans << endl;
    }
}
