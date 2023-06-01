#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> prefix0(n + 1), prefix1(n + 1);
    if (s[0] == '0')
        prefix0[1] = 1;
    if (s[0] == '1')
        prefix1[1] = 1;
    for (int i = 1; i < n; i++)
    {
        prefix0[i + 1] = prefix0[i] + (s[i] == '0');
        prefix1[i + 1] = prefix1[i] + (s[i] == '1');
    }
    int l = 0, r = n;
    int ans = n;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(s, mid, prefix0, prefix1))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
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
