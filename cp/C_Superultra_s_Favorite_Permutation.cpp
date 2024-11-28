#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isComposite(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return false;

    if (n % 2 == 0 || n % 3 == 0)
        return true;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;

        vector<int> odds, evens;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                odds.push_back(i);
            else
                evens.push_back(i);
        }
        bool is_possible = false;
        int od = -1, ev = -1;
        for (auto &even : evens)
        {
            for (auto &odd : odds)
            {
                if (isComposite(odd + even))
                {
                    od = odd;
                    ev = even;
                    is_possible = true;
                    break;
                }
            }
        }
        if (is_possible)
        {

            for (auto &even : evens)
            {
                if (even != ev)
                    cout << even << " ";
            }
            cout << ev << " " << od << " ";
            for (auto &odd : odds)
            {
                if (od != odd)
                    cout << odd << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << -1 << "\n";
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