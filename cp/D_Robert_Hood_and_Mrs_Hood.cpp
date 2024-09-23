#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        ll n, d, k;
        cin >> n >> d >> k;

        vector<int> pref(n + 1), suff(n + 1);
        for (int i = 0; i < k; i++)
        {
            int l, r;
            cin >> l >> r;
            pref[l]++;
            suff[r]++;
        }

        for (int i = 0; i < n; i++)
        {
            pref[i + 1] += pref[i];
            suff[i + 1] += suff[i];
        }

        int minv = 1e9, mini = 0, maxv = 0, maxi = 0;
        for (int i = d; i <= n; i++)
        {
            int curr = pref[i] - suff[i - d];
            if (curr > maxv)
            {
                maxi = i - d + 1;
                maxv = curr;
            }

            if (curr < minv)
            {
                mini = i - d + 1;
                minv = curr;
            }
        }
        cout << maxi << " " << mini << "\n";
    }
    return 0;
}
/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/