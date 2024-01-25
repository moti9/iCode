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

        string s, f;
        cin >> s;
        cin >> f;

        int add = 0, remove = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] < f[i])
                add += 1;
            else if (s[i] > f[i])
                remove += 1;
        }
        cout << max(add, remove) << endl;
    }
    return 0;
}