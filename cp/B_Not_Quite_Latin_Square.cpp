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
        vector<string> mat(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> mat[i];
        }
        int cntA = 0, cntB = 0, cntC = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cntA += (mat[i][j] == 'A');
                cntB += (mat[i][j] == 'B');
                cntC += (mat[i][j] == 'C');
            }
        }
        if (cntA == 2)
            cout << "A\n";
        else if (cntB == 2)
            cout << "B\n";
        else
            cout << "C\n";
    }
    return 0;
}