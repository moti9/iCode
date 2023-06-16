#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    int maxSteal(int ind, int wt, vector<int> &weight, vector<int> &value)
    {
        if (ind == 0)
        {
            if (weight[ind] <= wt)
            {
                return value[0];
            }
            return 0;
        }
        int notTake = maxSteal(ind - 1, wt, weight, value);
        int take = 0;
        if (weight[ind] <= wt)
        {
            take = value[ind] + maxSteal(ind - 1, wt - weight[ind], weight, value);
        }
        return max(take, notTake);
    }

public:
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
    {
        return maxSteal(n - 1, maxWeight, weight, value);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> value(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    int maxWeight;
    cin >> maxWeight;

    Solution sol;
    cout << sol.knapsack(weight, value, n, maxWeight) << endl;

    return 0;
}