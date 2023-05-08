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
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = nums[i];
            int j = i - 1;
            while (j >= 0 && temp <= nums[j])
            {
                nums[j + 1] = nums[j];
                j -= 1;
            }
            nums[j + 1] = temp;
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