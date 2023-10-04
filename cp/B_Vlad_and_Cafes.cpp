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
        // vector<int> indices(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            // cin >> indices[i];
            int indices;
            cin >> indices;
            mp[indices] = i;
        }
        int ans = -1;
        int recent = -1;
        for (auto &x : mp)
        {
            if (recent < n - x.second - 1)
            {
                ans = x.first;
                recent = n - x.second - 1;
            }
        }
        cout << ans << "\n";
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
