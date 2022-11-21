#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char ch;
                cin >> ch;
                if ((i == n && ch == 'D') || (j == m && ch == 'R'))
                {
                    count += 1;
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}