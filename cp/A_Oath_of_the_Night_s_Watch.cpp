#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class solution
{
public:
    solution()
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int mini = 1e9 + 2, maxi = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (mini < arr[i] && arr[i] < maxi)
            {
                cnt += 1;
            }
        }
        cout << cnt << "\n";
    }
};

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
        solution moti;
    }
    return 0;
}
