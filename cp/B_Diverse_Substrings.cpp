#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        vector<ll> freq(10, 0);
        ll uniq = 0, maxFreq = 0;

        for (ll j = i; j < n; j += 1)
        {
            ++freq[s[j] - '0'];
            if (freq[s[j] - '0'] <= 10)
            {
                maxFreq = max(maxFreq, freq[s[j] - '0']);
                if (freq[s[j] - '0'] == 1)
                {
                    uniq += 1;
                }
                if (uniq >= maxFreq)
                {
                    ans += 1;
                }
            }
            else
            {
                break;
            }
        }
    }
    cout << ans << "\n";
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
