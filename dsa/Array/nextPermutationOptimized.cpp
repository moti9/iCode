#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    void printNextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i -= 1;
        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = n - 1;
        while (j > i && nums[j] <= nums[i])
        {
            j -= 1;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
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
    Solution sol;
    sol.printNextPermutation(nums);
    for (auto n : nums)
        cout << n << " ";
    cout << endl;
    return 0;
}