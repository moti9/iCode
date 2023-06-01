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

    int cnt = 1, cost = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cnt += 1;
        }
        else
        {
            cost = max(cnt, cost);
            cnt = 1;
        }
    }
    cost = max(cnt, cost);
    cout << cost + 1 << "\n";
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
