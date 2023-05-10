#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(1)
// Linked-list cycle method
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.findDuplicate(nums) << endl;

    return 0;
}