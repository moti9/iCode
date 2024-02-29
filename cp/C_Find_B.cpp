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
        ll n, q;
        cin >> n >> q;
        vector<ll> prefixSum(n + 1);
        // vector<ll> arr(n);
        vector<ll> cnt1(n + 1);

        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            // cin >> arr[i];
            prefixSum[i + 1] = prefixSum[i] + a;
            // prefixSum[i + 1] = prefixSum[i] + arr[i];
            cnt1[i + 1] = cnt1[i] + (a == 1);
        }

        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            if (l == r)
            {
                cout << "NO\n";
                continue;
            }
            ll cnt = cnt1[r] - cnt1[l - 1];
            ll sum = prefixSum[r] - prefixSum[l - 1];

            ll req = (r - l + 1) + cnt;

            if (sum >= req)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}