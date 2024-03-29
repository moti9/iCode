/*
uestion 6: Buying Stocks
You are given a list of daily prices of a stock.
You can buy a stock on one day and sell it later on another day after the day you bought the stock. You can perform the above operation only once. What is the maximum loss possible?

Example

Prices=[10,4,2,9]

The greatest loss is incurred when you buy at a price
of 10 and sell at a price of 2. Return the difference:9.

Example

Price=[1,2,3,4]

The Price went up every day. Return 0.

Sample Input for Custom Testing

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int solve(vector v)
{
    int n = v.size();
    if (n == 0)
        return 0;
    int mx = v[0];
    for (int i = 1; i < n; i++)
        mx = max(mx, v[i]);
    if (mx <= 0)
        return 0;
    int mxSum = 0;
    int cSum = 0;
    for (int i = 0; i < n; i++)
    {
        cSum += v[i];
        if (cSum < 0)
            cSum = 0;
        mxSum = max(mxSum, cSum);
    }
    return mxSum;
}
int main()
{
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    vector diff;
    for (int i = n - 2; i >= 0; i--)
        diff.push_back(price[i] - price[i + 1]);
    int ans = solve(diff);
    if (ans < 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}