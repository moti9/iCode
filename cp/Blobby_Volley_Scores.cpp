#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sa = 0, sb = 0;
    char server = 'A';
    for (int i = 0; i < n; i++)
    {
        if (server == s[i])
        {
            if (server == 'A')
            {
                sa += 1;
            }
            else
            {
                sb += 1;
            }
        }
        else
        {
            if (server == 'A')
            {
                server = 'B';
            }
            else
            {
                server = 'A';
            }
        }
    }

    cout << sa << " " << sb << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
