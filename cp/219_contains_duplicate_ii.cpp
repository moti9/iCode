#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> umap;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];

            if (umap.find(num) != umap.end())
            {
                int j = umap[num];
                int diff = abs(i - j);
                if (diff <= k)
                {
                    return true;
                }
            }

            umap[num] = i;
        }

        return false;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    Solution sol = Solution();
    cout << (sol.containsNearbyDuplicate(nums, k) ? "Yes" : "No") << endl;

    return 0;
}