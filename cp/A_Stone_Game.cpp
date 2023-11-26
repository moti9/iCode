#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


void solvehere()
{
    int n;
    cin >> n;

    int maxVal = 0, maxInd = 0, minVal = INT_MAX, minInd = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x > maxVal)
        {
            maxVal = x;
            maxInd = i;
        }
        if (x < minVal)
        {
            minVal = x;
            minInd = i;
        }
    }

    int bothLeft = max(minInd, maxInd);
    int bothRight = n - min(minInd, maxInd) + 1;
    minInd = min(minInd, n - minInd + 1);
    maxInd = min(maxInd, n - maxInd + 1);
    int both = minInd + maxInd;

    cout << min({bothLeft, bothRight, both}) << "\n";
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
