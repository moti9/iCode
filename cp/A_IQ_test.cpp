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
    int a[100];
    int c_odd = 0, c_even = 0, leven = 0, lodd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            c_even++;
            leven = i;
        }
        else
        {
            c_odd++;
            lodd = i;
        }
    }
    if (c_odd == (n - 1))
    {
        cout << leven + 1 << "\n";
    }
    else
    {
        cout << lodd + 1 << "\n";
    }

    return 0;
}