#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N)
// SC- O(1)
// Dutch National Flag Algorithm
/*
Three rules-
1. [0,1,2,.....,low-1]---Extreme left
2. [low,low+1,low+2,.....,mid-1]
3. [high,high+1,high+2,.....,n-1]-----Extreme right
*/
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[high], nums[mid]);
                high--;
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