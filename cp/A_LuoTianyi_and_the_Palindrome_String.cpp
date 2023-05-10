#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// string print(string s, int i)
// {
//     int j = 0;
//     string sub;
//     while (i > 0)
//     {
//         if (i & 1)
//         {
//             sub.push_back(s[j]);
//         }
//         j++;
//         i = i >> 1;
//     }

//     return sub;
// }

bool check(string &s)
{
    int i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
void solvehere()
{
    string s;
    cin >> s;
    int ans = -1;
    // for (int i = 1; i <= ((1 << s.size()) - 1); i++)
    // {
    //     string st = print(s, i);
    //     int n = st.length();
    //     if (n > 1)
    //     {
    //         if (!check(st))
    //         {
    //             ans = max(ans, n);
    //         }
    //     }
    // }
    for (int i = 0; i < s.length(); i++)
    {
        string temp = s;
        temp.erase(temp.begin() + i);
        if (!check(temp))
        {
            ans = max(ans, (int)temp.length());
        }
    }
    cout << ans << endl;
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
