#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int clr[4];
    int oddct = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> clr[i];
        if (clr[i] % 2)
        {
            oddct += 1;
        }
    }
    if (oddct <= 1 || oddct == 4)
    {
        cout << "Yes\n";
        return;
    }
    if (oddct == 2)
    {
        cout << "No\n";
        return;
    }
    if (clr[0] && clr[1] && clr[2])
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
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
