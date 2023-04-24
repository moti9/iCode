#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> A(m, vector<int>(n, 1));
    int B[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> B[i][j];
            if (B[i][j] == 0)
            {
                for (int k = 0; k < m; k++)
                {
                    A[k][j] = 0;
                }
                for (int k = 0; k < n; k++)
                {
                    A[i][k] = 0;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (B[i][j] == 1)
            {
                int sum = 0;
                for (int k = 0; k < m; k++)
                {
                    sum += A[k][j];
                    if (sum > 0)
                    {
                        break;
                    }
                }
                for (int k = 0; k < n; k++)
                {
                    sum += A[i][k];
                    if (sum > 0)
                    {
                        break;
                    }
                }
                if (sum == 0)
                {
                    cout << "NO";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    ll ttt = 1;
    // cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
