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
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int start = -1, end = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 1)
            {
                if (start == -1)
                    start = i;
                end = i;
            }
        }
        if (start == -1 || end == -1)
        {
            cout << 0 << "\n";
        }
        else
        {
            int ans = 0;
            for (int i = start; i <= end; i++)
            {
                ans += (arr[i] == 0);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}