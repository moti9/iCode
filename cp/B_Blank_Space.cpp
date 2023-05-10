#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    vector<int> bin_num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bin_num[i];
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (bin_num[i] == 0)
        {
            cnt += 1;
        }
        else
        {
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
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
