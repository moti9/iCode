#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool check(ll m, ll n)
{
    if (n < 0 || n > m || (n != m && m & 1))
    {
        return false;
    }
    if (n == m)
    {
        return true;
    }
    if (check(m / 2, n - m / 2))
    {
        return true;
    }
    if (check(m / 2, n))
    {
        return true;
    }
    return false;
}

void solvehere()
{
    ll m, n;
    cin >> m >> n;
    if (n > m || (n != m && m & 1))
    {
        cout << "NO\n";
        return;
    }
    if (n == m)
    {
        cout << "YES\n";
        return;
    }

    if (check(m, n))
        cout << "YES\n";
    else
        cout << "NO\n";
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
