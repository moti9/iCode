#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool comp(const ll &a, const ll &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        ll n, k;
        cin >> n >> k;
        map<ll, ll> prod;
        for (ll i = 0; i < k; i++)
        {
            ll b, c;
            cin >> b >> c;
            prod[b] += c;
        }
        vector<ll> rec;
        for (auto &pr : prod)
            rec.push_back(pr.second);

        sort(rec.begin(), rec.end(), comp);

        ll sum = 0;
        for (ll i = 0; i < min(n, (ll)rec.size()); i++)
        {
            sum += rec[i];
        }
        cout << sum << "\n";
    }
    return 0;
}
/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/