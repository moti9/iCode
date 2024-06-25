#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n, m;
        cin >> n >> m;
        string a;
        cin >> a;
        vector<int> fr(7, m);
        for (int i = 0; i < n; i++)
        {
            fr[a[i] - 'A']--;
        }
        int ans = 0;
        for (int i = 0; i < 7; i++)
        {
            if (fr[i] > 0)
                ans += fr[i];
        }
        cout << ans << "\n";
    }
    return 0;
}