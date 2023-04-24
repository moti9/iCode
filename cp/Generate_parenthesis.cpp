#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve(int left, int right, vector<string> &ans, string ds)
{
    if (left == 0 && right == 0)
    {
        ans.push_back(ds);
        return;
    }
    if (left > 0)
    {
        solve(left - 1, right, ans, ds + '(');
    }
    if (right > left)
    {
        solve(left, right - 1, ans, ds + ')');
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    solve(n, n, ans, "");
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<string> ans = generateParenthesis(n);
    for (auto x : ans)
    {
        cout << x << endl;
    }

    return 0;
}