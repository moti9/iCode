#include <bits/stdc++.h>
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int main()
{
    fastio();
    int n, m;
    cin >> n >> m;
    int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    bool flag = false;
    for (int i = 0; i < 60; i++)
    {
        if (a[i] == n && a[i + 1] == m)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}