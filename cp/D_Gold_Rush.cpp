#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool solve(int n, int m)
{
    if (n % 3 != 0)
        return false;
    int left = n / 3;
    int right = left * 2;
    if (left == m || right == m)
        return true;
    if (left > m && solve(left, m))
        return true;
    if (right > m && solve(right, m))
        return true;
    return false;
}

void solvehere()
{
    int n, m;
    cin >> n >> m;
    if (n < m)
    {
        cout << "NO\n";
        return;
    }
    if (n == m)
    {
        cout << "YES\n";
        return;
    }
    if (solve(n, m))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
