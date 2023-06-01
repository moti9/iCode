#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int p, s;
    cin >> p >> s;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= p; i++)
    {
        vector<pair<int, int>> arr;
        for (int j = 0; j < s; j++)
        {
            int sc;
            cin >> sc;
            arr.push_back({sc, 0});
        }
        for (int j = 0; j < s; j++)
        {
            int ps;
            cin >> ps;
            arr[j].second = ps;
        }
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for (int j = 1; j < s; j++)
        {
            cnt += arr[j].second < arr[j - 1].second;
        }
        ans.push_back({cnt, i});
    }
    sort(ans.begin(), ans.end());
    for (auto a : ans)
        cout << a.second << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
