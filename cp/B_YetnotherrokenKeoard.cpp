#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    string s;
    cin >> s;
    int cntb = 0, cntB = 0;
    string result = "";
    int len = s.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (s[i] == 'b')
            {
                cntb += 1;
            }
            else if (cntb > 0)
            {
                cntb -= 1;
            }
            else
            {
                result += s[i];
            }
        }
        else
        {
            if (s[i] == 'B')
            {
                cntB += 1;
            }
            else if (cntB > 0)
            {
                cntB -= 1;
            }
            else
            {
                result += s[i];
            }
        }
        // cout << result << "\n";
    }
    reverse(result.begin(), result.end());
    cout << result << "\n";
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
