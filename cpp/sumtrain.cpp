#include <iostream>

using namespace std;
int main()
{
    short t;
    cin >> t;
    while (t--)
    {
        short n;
        short a[n][n];
        cin >> n;
        for (short i = 0; i < n; i++)
        {
            for (short j = 0; j <= i; j++)
            {
                cin >> a[i][j];
            }
        }
        short maxm = 0;
        for (short i = n - 1; i > 0; i--)
        {
            for (short j = 0; j < i; j++)
            {
                maxm = max(a[i][j], a[i][j + 1]);
                a[i - 1][j] += maxm;
            }
        }
        cout << a[0][0] << endl;
    }

    return 0;
}
