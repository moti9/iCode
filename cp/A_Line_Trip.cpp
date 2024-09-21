#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int tank, unordered_set<int> &gas, int x)
{
    int fuel = tank;
    for (int pos = 1; pos <= 2 * x; pos++)
    {
        fuel--;
        if (fuel < 0)
            return false;

        int curr_pos = pos <= x ? pos : 2 * x - pos;

        if (gas.count(curr_pos) > 0)
        {
            fuel = tank;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll ttt;
    cin >> ttt;
    while (ttt--)
    {
        int n, x;
        cin >> n >> x;
        unordered_set<int> gas;

        for (int i = 0; i < n; i++)
        {
            int cord;
            cin >> cord;
            gas.insert(cord);
        }

        int left = 1, right = 2 * x;
        int ans = right;

        while (left <= right)
        {
            int mid = (right + left) / 2;
            if (check(mid, gas, x))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
