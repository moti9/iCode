#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c)
    {
        cout << "Yes\n";
        return;
    }
    if (a == b)
    {
        if ((c % a) % b == 0 || (c % b) % a == 0)
        {
            cout << "Yes\n";
            return;
        }
        else
        {
            cout << "No\n";
            return;
        }
    }
    if (a == c)
    {
        if ((b % a) % c == 0 || (b % c) % a == 0)
        {
            cout << "Yes\n";
            return;
        }
        else
        {
            cout << "No\n";
            return;
        }
    }
    if (c == b)
    {
        if ((a % c) % b == 0 || (a % b) % c == 0)
        {
            cout << "Yes\n";
            return;
        }
        else
        {
            cout << "No\n";
            return;
        }
    }
    if ((b - a) > 0 && (c - b) > 0 && (a - c) > 0)
    {
        cout << "Yes\n";
        return;
    }
    if ((a - b) > 0 && (b - c) > 0 && (c - a) > 0)
    {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
