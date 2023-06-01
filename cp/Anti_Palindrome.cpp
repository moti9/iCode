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
    unordered_map<char, int> mp;
    for (auto c : s)
        mp[c]++;
    int cntodd = 0;
    for (auto m : mp)
        if (m.second & 1)
            cntodd += 1;

    if (cntodd > 1)
    {
        cout << 0 << "\n";
        return;
    }
    // Odd
    if (n & 1)
    {
        if (cntodd == 0)
        {
            cout << 0;
        }
        else
        {
            if (mp.size() == 1)
                cout << 2;
            else
                cout << 1;
        }
        cout << "\n";
        return;
    }
    // Even
    if (cntodd == 0)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
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
