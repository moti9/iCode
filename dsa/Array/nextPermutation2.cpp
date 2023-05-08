#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
private:
public:
    vector<int> nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
        return nums;
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
    vector<int> ans = sol.nextPermutation(nums);
    for (auto a : ans)
        cout << a << " ";
    cout << "\n";

    return 0;
}