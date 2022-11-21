#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    ll n, k;
    cin >> n >> k;
    ll sum = (k * (k + 1) / 2) - 1;
    if (n > sum)
    {
        cout << -1;
        return;
    }
    ll ans = -1;
    ll low = 0, high = k - 1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        sum = mid * (2 * k - mid - 1) / 2;
        if (n - 1 <= sum)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;
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
