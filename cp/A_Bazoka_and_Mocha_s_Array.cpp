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

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> cp = arr;
        sort(cp.begin(), cp.end());
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            flag = true;
            for (int j = 0; j < n; j++)
            {
                if (arr[(i + j) % n] != cp[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}