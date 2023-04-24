#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    string t1, t2;
    cin >> t1;
    cin >> t2;

    int h1 = (t1[0] - '0') * 10 + (t1[1] - '0');
    int m1 = (t1[3] - '0') * 10 + (t1[4] - '0');
    int h2 = (t2[0] - '0') * 10 + (t2[1] - '0');
    int m2 = (t2[3] - '0') * 10 + (t2[4] - '0');

    int total = ((h1 + h2) * 60 + (m1 + m2)) / 2;
    int hr = total / 60;
    int mn = total % 60;
    if (hr < 10)
    {
        cout << 0;
    }
    cout << hr << ":";
    if (mn < 10)
    {
        cout << 0;
    }
    cout << mn;
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
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
