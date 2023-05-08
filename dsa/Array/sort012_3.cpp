#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N)
// SC- O(1)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 0; i < nums.size() - 1; i += 2)
            {
                if (nums[i] <= nums[i + 1])
                    continue;
                swap(nums[i], nums[i + 1]);
                flag = true;
            }
            for (int i = 1; i < nums.size() - 1; i += 2)
            {
                if (nums[i] <= nums[i + 1])
                    continue;
                swap(nums[i], nums[i + 1]);
                flag = true;
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