#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n, m;
        cin >> n >> m;

        int mat[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        // while (true)
        // {
        //     int counter = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                bool flag = true;
                int ops_val = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                    {
                        if (mat[i][j] > mat[nrow][ncol])
                        {
                            ops_val = max(ops_val, mat[nrow][ncol]);
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    mat[i][j] = ops_val;
                    // counter += 1;
                }
            }
        }

        //     if (counter == 0)
        //     {
        //         break;
        //     }
        // }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
        // cout << "\n";
    }
    return 0;
}