#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using two pointer
// TC- O(N)+O(NlogN)
// SC- O(1)

class Solution
{
public:
    string twoSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == target)
                return "YES";
            else if (sum > target)
                right -= 1;
            else
                left += 1;
        }
        return "NO";
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;

    Solution sol;
    cout << sol.twoSum(nums, target) << endl;

    return 0;
}