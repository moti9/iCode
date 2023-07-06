#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findCost(int i, int j, vector<int> &cuts)
    {
        if (i > j)
        {
            return 0;
        }
        int minCost = 1e9;

        for (int ind = i; ind <= j; ind++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + findCost(i, ind - 1, cuts) + findCost(ind + 1, j, cuts);
            minCost = min(minCost, cost);
        }

        return minCost;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        vector<int> copyCuts(m + 2);
        copy(cuts.begin(), cuts.end(), copyCuts.begin() + 1);
        copyCuts[m + 1] = n;

        sort(copyCuts.begin(), copyCuts.end());
        return findCost(1, m, copyCuts);
    }
};

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<int> cuts(m);
    for (int i = 0; i < m; i++)
    {
        cin >> cuts[i];
    }

    Solution sol;
    cout << sol.minCost(n, cuts) << endl;

    return 0;
}