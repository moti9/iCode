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
        if (n % 2 == 0)
        {
            cout << "-1\n";
            continue;
        }
        // vector<int> permut(n, -1);
        // permut[n / 2] = 1;
        // int val = n;
        for (int i = 0; i < n / 2; i++)
        {
            // permut[i] = val--;
            // permut[n - i - 1] = val--;
            cout << (n - i) << " " << (i + 1) << " ";
        }
        cout << (n + 1) / 2 << "\n";

        // for (int i = 0; i < n; i++)
        // {
        //     cout << permut[i] << " ";
        // }
    }
    return 0;
}