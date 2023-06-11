#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(1)

class Solution
{
public:
    int frogJump(int n, vector<int> &heights)
    {
        int prev = 0, prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int left = prev + abs(heights[i] - heights[i - 1]);
            int right = INT_MAX;
            if (i > 1)
            {
                right = prev2 + abs(heights[i] - heights[i - 2]);
            }
            int curr = min(left, right);
            prev2 = prev;
            prev = curr;
        }
        return prev;
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