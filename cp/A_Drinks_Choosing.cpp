#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int one = 0, two = 0;
    for (auto x : mp)
    {
        two += (x.second / 2);
        one += (x.second % 2);
    }
    int total = (n + 1) / 2;
    int rem = total - two;
    if (one <= rem)
    {
        cout << n;
        return;
    }
    cout << 2 * two + rem;
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
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
