#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 0)
    {
        cout << 0 << "\n";
        return;
    }
    int card = n / k;
    if (card >= m)
    {
        cout << m << "\n";
    }
    else
    {
        m -= card;
        if (m < k)
        {
            cout << card - 1 << "\n";
            return;
        }
        int smx = (m + k - 2) / (k - 1);
        cout << card - smx << "\n";
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
