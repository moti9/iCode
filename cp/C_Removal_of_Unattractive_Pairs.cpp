#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// int findOps(string &s)
// {
//     string ans = "";
//     for (auto &c : s)
//     {
//         if (ans == "")
//         {
//             ans += c;
//         }
//         else if (ans.back() != c)
//         {
//             ans.pop_back();
//         }
//         else
//         {
//             ans += c;
//         }
//     }
//     return ans.length();
// }

void solvehere()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // int ans = findOps(s);
    // reverse(s.begin(), s.end());
    // ans = min(ans, findOps(s));
    // cout << ans << "\n";

    vector<int> freq(26);
    for (auto &c : s)
    {
        freq[c - 'a'] += 1;
    }
    int needFr = *max_element(freq.begin(), freq.end()) * 2;
    if (needFr < n)
    {
        cout << n % 2 << "\n";
    }
    else
    {
        cout << needFr - n << "\n";
    }
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
