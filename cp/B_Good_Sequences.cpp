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
    // cin>>ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> dp(1e5 + 2);
        for (auto &a : arr)
        {
            dp[a] = 1;
            vector<int> fts;
            for (int i = 2; i * i <= a; i++)
            {
                if (a % i == 0)
                {
                    fts.push_back(i);
                    if (a / i != i)
                    {
                        fts.push_back(a / i);
                    }
                }
            }

            int cnt = 0;
            for (auto &ft : fts)
            {
                cnt = max(cnt, dp[ft]);
            }
            for (auto &ft : fts)
            {
                dp[ft] = cnt + 1;
            }
        }

        int ans = 0;
        for (auto &d : dp)
            ans = max(ans, d);
        cout << ans << endl;
    }
    return 0;
}
