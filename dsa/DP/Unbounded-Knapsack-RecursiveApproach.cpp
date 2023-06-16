#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    int maxProfit(int ind, int wt, vector<int> &profit, vector<int> &weight)
    {
        if (ind == 0)
        {
            return (wt / weight[0]) * profit[0];
        }
        int notTake = maxProfit(ind - 1, wt, profit, weight);
        int take = 0;
        if (weight[ind] <= wt)
        {
            take = profit[ind] + maxProfit(ind, wt - weight[ind], profit, weight);
        }
        return max(take, notTake);
    }

public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        return maxProfit(n - 1, w, profit, weight);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> profit(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i] >> weight[i];
    }
    int wt;
    cin >> wt;

    Solution sol;
    cout << sol.unboundedKnapsack(n, wt, profit, weight) << endl;

    return 0;
}