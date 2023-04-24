#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int num[3];
    cin >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);
    if (num[1] != num[2])
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << num[0] << " " << num[0] << " " << num[2] << "\n";
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
