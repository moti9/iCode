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
        int n, f, k;
        cin >> n >> f >> k;
        f -= 1;
        k -= 1;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int x = arr[f];
        sort(arr.rbegin(), arr.rend());

        if (arr[k] > x)
            cout << "NO\n";
        else if (arr[k] < x)
            cout << "YES\n";
        else
        {
            if ((k == n - 1) || (arr[k + 1] < x))
                cout << "YES\n";
            else
                cout << "MAYBE\n";
        }
    }
    return 0;
}