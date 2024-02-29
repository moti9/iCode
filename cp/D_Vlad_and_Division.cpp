#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            int complement = (1 << 31) - 1 - x;
            if (mp[complement] > 0)
            {
                ans++;
                mp[complement]--;
            }
            else
            {
                mp[x]++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
