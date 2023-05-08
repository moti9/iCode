#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N+N)==O(N)
// SC- O(1)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (auto n : nums)
        {
            if (n == 0)
                cnt0 += 1;
            else if (n == 1)
                cnt1 += 1;
            else
                cnt2 += 1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt0)
            {
                nums[i] = 0;
                cnt0 -= 1;
            }
            else if (cnt1)
            {
                nums[i] = 1;
                cnt1 -= 1;
            }
            else if (cnt2)
            {
                nums[i] = 2;
                cnt2 -= 1;
            }
        }
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
    sol.sortColors(arr);

    for (auto a : arr)
        cout << a << " ";
    cout << endl;

    return 0;
}