#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rnd(228);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }
    int l = -1, r = m;
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        int prev = 0;
        bool bad = false;
        for (int i = 0; i < n; i++)
        {
            int lf = a[i], rf = a[i] + mid;
            if ((lf <= prev && prev <= rf) || (lf <= prev + m && prev + m <= rf))
            {
                continue;
            }
            if (lf < prev)
            {
                bad = true;
                break;
            }
            else
            {
                prev = lf;
            }
        }
        if (bad)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << r << '\n';
}