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
        unordered_map<int, int> mp;
        mp[1]++;
        cout << mp.size();
        mp[1] = 0;
        cout << mp.size();
    }
    return 0;
}