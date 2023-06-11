#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    int findMinEnergy(int ind, vector<int> &heights)
    {
        if (ind == 0)
        {
            return 0;
        }
        int left = findMinEnergy(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
        int right = INT_MAX;
        if (ind > 1)
            right = findMinEnergy(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
        return min(left, right);
    }

public:
    int frogJump(int n, vector<int> &heights)
    {
        return findMinEnergy(n - 1, heights);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    Solution sol;
    cout << sol.frogJump(n, heights) << endl;

    return 0;
}