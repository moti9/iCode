#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n, m;
    cin >> n >> m;
    int step = (n / 2);
    int total = step + (n % 2);
    if (total % m == 0)
    {
        cout << total;
        return;
    }
    int temp = total;
    while (step > 0)
    {
        temp++;
        if (temp % m == 0)
        {
            cout << temp;
            return;
        }
        step--;
    }
    cout << -1;
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
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
