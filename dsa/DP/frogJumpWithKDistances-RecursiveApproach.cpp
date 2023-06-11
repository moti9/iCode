#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(K*2^N)
// SC- O(N)

class Solution
{
    int findMinEnergy(int ind, int k, vector<int> &heights)
    {
        if (ind == 0)
        {
            return 0;
        }
        int minEng = INT_MAX;

        for (int dist = 1; dist <= k; dist++)
        {
            if (ind - dist >= 0)
            {
                int jump = findMinEnergy(ind - dist, k, heights) + abs(heights[ind] - heights[ind - dist]);
                minEng = min(minEng, jump);
            }
            else
            {
                break;
            }
        }

        return minEng;
    }

public:
    int frogJumpWithKDistance(int n, int k, vector<int> &heights)
    {
        return findMinEnergy(n - 1, k, heights);
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    Solution sol;
    cout << sol.frogJumpWithKDistance(n, k, heights) << endl;

    return 0;
}