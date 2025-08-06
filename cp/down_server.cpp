#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007
#define ll long long int



ll getMinRequests(vector<ll> &req, vector<ll> &health, int k)
{
    int n = req.size();
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll minReq = (health[i] + k - 1) / k;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> requests(n);
    for (int i = 0; i < n; i++)
    {
        cin >> requests[i];
    }

    int m;
    cin >> m;
    vector<ll> health(m);
    for (int i = 0; i < m; i++)
    {
        cin >> health[i];
    }

    int k;
    cin >> k;

    cout << getMinRequests(requests, health, k) << endl;

    return 0;
}