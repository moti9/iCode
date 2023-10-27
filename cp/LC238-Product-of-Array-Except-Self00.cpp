#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{

public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = 1;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            prefix[i] *= suffix;
            suffix *= nums[i];
        }
        return prefix;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution sol;
    vector<int> ans = sol.productExceptSelf(arr);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}