#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll ttt;
    cin >> ttt;

    while (ttt--)
    {
        int n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;

        bool possible = false;

        for (int i = 0; i < n; i++)
        {
            bool condition = (a[i] != c[i] && b[i] != c[i]);
            if (condition)
            {
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}
