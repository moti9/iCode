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
    // cin>>ttt;
    while (ttt--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int gi = s.find('G');
        int ti = s.find('T');
        int left = min(gi, ti);
        int right = max(gi, ti);

        if ((right - left) % k != 0)
        {
            cout << "NO\n";
            continue;
        }

        for (int i = left; i <= right; i += k)
        {
            if (s[i] == '#')
            {
                cout << "NO\n";
                return 0;
            }
        }

        cout << "YES\n";
    }
    return 0;
}
