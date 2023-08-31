#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        vector<long long> adjWeights(n - 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            adjWeights[i] = weights[i] + weights[i + 1];
        }

        sort(adjWeights.begin(), adjWeights.end());

        long long adjWt = 0;

        for (int i = 0; i < k - 1; i++)
        {
            adjWt += adjWeights[n - i - 2] - adjWeights[i];
        }

        return adjWt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    int k;
    cin >> k;

    Solution sol;
    cout << sol.putMarbles(weights, k) << endl;

    return 0;
}