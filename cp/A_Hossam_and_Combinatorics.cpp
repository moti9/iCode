#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    // vector<int> nums(n);
    unordered_map<int, int> mp;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // cin >> nums[i];
        int x;
        cin >> x;
        mini = min(mini, x);
        maxi = max(maxi, x);
        mp[x]++;
    }
    /*
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = abs(nums[i] - nums[j]);
            mp[temp]++;
        }
    }
    int ans = 0, val = -1;
    for (auto x : mp)
    {
        if (x.first >= val)
        {
            val = x.first;
            ans = max(ans, x.second);
        }
    }
    */
    // cout << ans * 2 << endl;
    if (maxi - mini == 0)
    {
        cout << (ll)n * (ll)(n - 1) << endl;
    }
    else
        cout << (ll)mp[maxi] * (ll)mp[mini] * (ll)2 << endl;
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
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
