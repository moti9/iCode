#include <bits/stdc++.h>
using namespace std;

int func(int s, int p, int n)
{
    if (p == n - 1)
        return 1;
    int ans = 0;
    for (int i = s; i <= 9; i++)
        ans += func(i, p + 1, n);
    return ans;
}

int main()
{
    int n, a, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        for (int i = 0; i <= 9; i++)
            ans += func(i, 0, a);
    }
    cout << ans;
}