#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        vector<string> op(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> op[i];
            mp[op[i]]++;
        }
        cout << mp[op[0]] << endl;
    }

    return 0;
}