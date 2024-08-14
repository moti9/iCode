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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        bool isEqual = true;
        bool isReverseEqual = true;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                isEqual = false;
            if (a[i] != b[n - 1 - i])
                isReverseEqual = false;
        }

        if (isEqual || isReverseEqual)
        {
            cout << "Bob\n";
        }
        else
        {
            cout << "Alice\n";
        }
    }
    return 0;
}