#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

#define ll long long

class SegmentTree
{
public:
    vector<ll> segTree;
    SegmentTree(ll n)
    {
        segTree.resize(4 * n);
    }

    void build(ll index, ll left, ll right, vector<ll> &freq)
    {
        if (left == right)
        {
            segTree[index] += freq[left];
            return;
        }
        ll mid = (left + right) / 2;
        build(2 * index + 1, left, mid, freq);
        build(2 * index + 2, mid + 1, right, freq);
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    void update(ll index, ll left, ll right, ll pos)
    {
        if (left == right)
        {
            segTree[index]--;
            return;
        }
        ll mid = (left + right) / 2;
        if (pos <= mid)
        {
            update(2 * index + 1, left, mid, pos);
        }
        else
        {
            update(2 * index + 2, mid + 1, right, pos);
        }
        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    ll query(ll index, ll left, ll right, ll ql, ll qr)
    {
        if (right < ql || left > qr)
        {
            return 0;
        }
        if (left >= ql && right <= qr)
        {
            return segTree[index];
        }
        ll mid = (left + right) / 2;
        return query(2 * index + 1, left, mid, ql, qr) + query(2 * index + 2, mid + 1, right, ql, qr);
    }
};

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll maxVal = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxVal = max(maxVal, (ll)arr[i]);
    }
    vector<ll> freq(maxVal + 1, 0);
    for(ll i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    SegmentTree segTree(maxVal + 1);
    segTree.build(0, 0, maxVal, freq);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        freq[arr[i]]--;
        segTree.update(0, 0, maxVal, arr[i]);
        ans += segTree.query(0, 0, maxVal, 0, arr[i] - 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll tt;
    cin>>tt;
    while(tt--){
        solve();
    }

    return 0;
}