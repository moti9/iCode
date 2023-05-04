#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << n << "\n";
        return;
    }
    if (n & 1)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n / 2; i++)
    {
        int temp = 2 * i;
        cout << temp << " " << temp - 1 << " ";
    }
    cout << "\n";
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
