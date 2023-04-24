#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp.push_back({x, i + 1});
    }
    sort(mp.begin(), mp.end());
    vector<int> index;
    // for (auto x : mp)
    //     cout << x.first << " " << x.second << endl;
    for (auto x : mp)
    {
        if (k >= x.first)
        {
            index.push_back(x.second);
            k -= x.first;
        }
        else
        {
            break;
        }
    }
    int sz = index.size();
    cout << sz << endl;
    for (int i = 0; i < sz; i++)
    {
        cout << index[i] << " ";
    }
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
