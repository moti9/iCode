#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int main()
{
    fastio();
    int n;
    cin >> n;
    int i = 2, j = 1;
    if (n % 2 == 1)
    {
        cout << -1;
    }
    else
    {
        while (i <= n)
        {
            cout << i << " " << j << " ";
            i += 2;
            j += 2;
        }
    }

    return 0;
}