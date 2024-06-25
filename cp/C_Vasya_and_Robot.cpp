#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void move_update(pair<int, int> &pos, char move, int dir)
{
    if (move == 'U')
        pos.second += dir;
    else if (move == 'D')
        pos.second -= dir;
    else if (move == 'L')
        pos.first -= dir;
    else
        pos.first += dir;
}

bool isPossible(pair<int, int> &u, pair<int, int> v, int l)
{
    int d = abs(u.first - v.first) + abs(u.second - v.second);
    if (l % 2 != d % 2)
        return false;
    return d <= l;
}

bool solve(int len, int n, string &s, int x, int y)
{
    pair<int, int> pos = {0, 0};
    for (int i = len; i < n; i++)
    {
        move_update(pos, s[i], 1);
    }

    int l = 0, r = len;
    while (true)
    {
        if (isPossible(pos, {x, y}, len))
            return true;
        if (r == n)
            break;
        move_update(pos, s[l++], 1);
        move_update(pos, s[r++], -1);
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x, y;
        cin >> x >> y;

        if (!solve(n, n, s, x, y))
        {
            cout << "-1\n";
            return 0;
        }

        int l = -1, r = n;
        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            if (solve(mid, n, s, x, y))
                r = mid;
            else
                l = mid;
        }
        cout << r << "\n";
    }
    return 0;
}