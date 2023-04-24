#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i <= n / 2; i++)
    {
        if (s[i] == '1' || s[n - i - 1] == '1')
        {
            cout << 2 * (n - i) << "\n";
            return;
        }
    }
    cout << n << "\n";
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
    cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
