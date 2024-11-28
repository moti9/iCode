#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

set<pair<ll, ll>> find_pos(ll a, ll b, ll x, ll y)
{
    set<pair<ll, ll>> cords;

    cords.insert({x - a, y + b});
    cords.insert({x + a, y + b});

    cords.insert({x - a, y - b});
    cords.insert({x + a, y - b});

    cords.insert({x - b, y + a});
    cords.insert({x - b, y - a});

    cords.insert({x + b, y + a});
    cords.insert({x + b, y - a});

    return cords;
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
        ll a, b;
        cin >> a >> b;

        ll xk, yk;
        cin >> xk >> yk;

        ll xq, yq;
        cin >> xq >> yq;

        set<pair<ll, ll>> coord_k = find_pos(a, b, xk, yk);
        set<pair<ll, ll>> coord_q = find_pos(a, b, xq, yq);
        ll cnt = 0;
        for (auto &ck : coord_k)
        {
            if (coord_q.count(ck) > 0)
            {
                // if (max(abs(xk - ck.first), abs(yk - ck.second)) == 1)
                //     continue;
                // if (abs(xq - ck.first) == abs(yq - ck.second))
                //     continue;

                cnt += 1;
            }
        }
        cout << cnt << "\n";
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