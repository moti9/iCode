#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int cnt0 = 0, cntod = 0, cntev = 0;
    int minodd = 1e9 + 1, minev = 1e9 + 2;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            cnt0 += 1;
        }
        else if (arr[i] & 1)
        {
            cntod += 1;
            minodd = min(minodd, arr[i]);
        }
        else
        {
            minev = min(minev, arr[i]);
            cntev += 1;
        }
    }
    if (cnt0 != 0)
    {
        cout << "NO\n";
        return;
    }

    if (cntev == n || cntod == n)
    {
        cout << "YES\n";
        return;
    }

    if (minodd < minev)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
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
