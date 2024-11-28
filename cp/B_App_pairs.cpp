#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ttt;
    cin >> ttt;
    while (ttt--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> xcord(n);
        vector<pair<ll, ll>> events;

        for (ll i = 0; i < n; i++)
        {
            cin >> xcord[i];
        }

        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                ll start = xcord[i];
                ll end = xcord[j];
                events.push_back({start, 1});
                events.push_back({end + 1, -1});
            }
        }

        sort(events.begin(), events.end());

        vector<ll> qs(q);
        for (ll i = 0; i < q; i++)
        {
            cin >> qs[i];
        }

        map<ll, ll> freq;
        ll curr_cnt = 0, prev = events[0].first;

        for (ll i = 0; i < events.size(); i++)
        {
            ll position = events[i].first;

            if (position > prev)
            {
                freq[curr_cnt] += position - prev;
            }

            curr_cnt += events[i].second;
            prev = position;
        }

        for (ll i = 0; i < q; i++)
        {
            cout << freq[qs[i]] << " ";
        }
        cout << "\n";
    }

    return 0;
}