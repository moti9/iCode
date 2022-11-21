#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int main()
{
    fastio();
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= a[k - 1] && a[i] != 0)
        {
            ct++;
        }
    }
    cout << ct << endl;

    return 0;
}