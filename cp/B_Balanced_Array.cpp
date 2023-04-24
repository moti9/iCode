#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    int term = n / 2;
    if (term % 2)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int sum = 0;
    for (int i = 1; i <= term; i++)
    {
        cout << i * 2 << " ";
        sum += (2 * i);
    }
    for (int i = 1; i < term; i++)
    {
        cout << (2 * i - 1) << " ";
        sum -= (2 * i - 1);
    }
    cout << sum << "\n";
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
