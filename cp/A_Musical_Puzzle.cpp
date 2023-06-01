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
    unordered_map<string, int> mp;
    for (int i = 1; i < n; i++)
    {
        string temp = s.substr(i - 1, 2);
        mp[temp]++;
    }
    cout << mp.size() << endl;
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
