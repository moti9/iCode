#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int getNumberOfWays(vector<vector<int>> a, int d)
{
    int n = a.size();
    int m = a[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the base case
    dp[0][0] = (a[0][0] == 0) ? 0 : 1;

    // Fill the first row
    for (int j = 1; j < m; ++j)
    {
        if (a[0][j] == 0 || abs(j - d) <= d)
        {
            break; // Blocked cell or blocked by Manhattan distance
        }
        dp[0][j] = 1;
    }

    // Fill the first column
    for (int i = 1; i < n; ++i)
    {
        if (a[i][0] == 0 || abs(i - d) <= d)
        {
            break; // Blocked cell or blocked by Manhattan distance
        }
        dp[i][0] = 1;
    }

    // Fill the rest of the dp matrix
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (a[i][j] == 0 || abs(i - d) <= d || abs(j - d) <= d)
            {
                continue; // Blocked cell or blocked by Manhattan distance
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    int n, m, d;
    cout << "Enter the number of rows (n): ";
    cin >> n;

    cout << "Enter the number of columns (m): ";
    cin >> m;

    vector<vector<int>> a(n, vector<int>(m));

    cout << "Enter the matrix a[" << n << "][" << m << "]:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter the Manhattan distance (d): ";
    cin >> d;

    int result = getNumberOfWays(a, d);

    cout << "Number of ways to reach (n-1, m-1) without passing through blocked cells: " << result << endl;

    return 0;
}
