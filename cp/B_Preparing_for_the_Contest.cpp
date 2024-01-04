#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n, k;
    cin >> n >> k;
    vector<int> order(n);
    for (int i = 0; i < n; i++)
    {
        order[i] = n - i;
    }
    reverse(order.begin() + (n - k - 1), order.end());
    for (auto &o : order)
    {
        cout << o << " ";
    }
    cout << "\n";
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
