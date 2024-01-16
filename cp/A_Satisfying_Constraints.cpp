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
        unordered_map<int, int> mp3;
        int mp1 = 0, mp2 = 1e9 + 2;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a, x;
            cin >> a >> x;
            if (a == 1)
            {
                mp1 = max(mp1, x);
            }
            else if (a == 2)
            {
                mp2 = min(mp2, x);
            }
            else
            {
                mp3[x] += 1;
            }
        }
        if (mp1 > mp2)
        {
            cout << 0 << "\n";
        }
        else
        {
            int cnt = mp2 - mp1 + 1;
            for (auto &x : mp3)
            {
                if (mp1 <= x.first && x.first <= mp2)
                {
                    cnt -= 1;
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}