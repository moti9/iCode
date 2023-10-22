#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int lowerBound(vector<int> &arr, int n, int x)
    {
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (arr[mid] >= x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

public:
    int findRowWithMax1s(vector<vector<int>> &matrix, int n, int m)
    {
        int index = -1, cntMax = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = m - lowerBound(matrix[i], m, 1);
            if (cntMax < cnt)
            {
                cntMax = cnt;
                index = i;
            }
        }
        return index;
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
    cout << sol.findRowWithMax1s(matrix, n, m) << endl;

    return 0;
}