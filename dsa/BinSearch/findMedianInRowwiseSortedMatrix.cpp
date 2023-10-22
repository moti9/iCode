#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int countSmalEqual(vector<vector<int>> &mat, int n, int m, int x)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += (m - (upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin()));
        }
        return cnt;
    }

public:
    int findMedian(vector<vector<int>> &matrix, int n, int m)
    {
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        int req = (n + m) >> 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int cnt = countSmalEqual(matrix, n, m, mid);
            if (cnt <= req)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    cout << sol.findMedian(matrix, n, m) << endl;

    return 0;
}