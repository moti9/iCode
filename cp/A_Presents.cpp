#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        v[p] = i + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}