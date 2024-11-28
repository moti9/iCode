#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n, m, L;
        cin >> n >> m >> L;

        vector<tuple<int, int, int>> hp;
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            hp.push_back({l, r, 1});
        }
        for (int i = 0; i < m; i++)
        {
            int x, v;
            cin >> x >> v;
            hp.push_back({x, v, 0});
        }

        sort(hp.begin(), hp.end());

        priority_queue<int> ups;
        int jump = 1;
        bool is_found = true;

        for (auto &[a, b, flag] : hp)
        {
            if (flag == 0)
            {
                ups.push(b);
            }
            else
            {
                while (!ups.empty() && jump < b - a + 2)
                {
                    jump += ups.top();
                    ups.pop();
                }

                if (jump < b - a + 2)
                {
                    cout << -1 << "\n";
                    is_found = false;
                    break;
                }
            }
        }

        if (is_found)
        {
            cout << m - ups.size() << "\n";
        }
    }
    return 0;
}
/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/