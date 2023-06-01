#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void subsequences(int index, int n, vector<int> &arr, vector<int> &subarr, ll &ans)
{
    if (index == n)
    {
        sort(subarr.begin(), subarr.end());
        int cnt = 0;
        for (int i = 0; i < subarr.size(); i++)
        {
            if (i + 1 == subarr[i])
                cnt += 1;
        }
        ans += cnt;
        ans %= mod;
        // subarr.clear();
        return;
    }

    subarr.push_back(arr[index]);
    subsequences(index + 1, n, arr, subarr, ans);
    subarr.pop_back();
    subsequences(index + 1, n, arr, subarr, ans);
}

void solvehere()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> subarr;
    ll ans = 0;
    subsequences(0, n, arr, subarr, ans);
    cout << ans << "\n";
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
