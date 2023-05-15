#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Optimal Solutin- Merge Sort Alogrithm
// TC- O(NlogN)+O(N)+O(N)
// SC- O(N)

class Solution
{
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        int cnt = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && nums[i] > 2LL * nums[j])
            {
                j += 1;
            }
            cnt += (j - (mid + 1));
        }
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left += 1;
            }
            else
            {
                temp.push_back(nums[right]);
                right += 1;
            }
        }
        while (left <= mid)
        {
            temp.push_back(nums[left]);
            left += 1;
        }
        while (right <= high)
        {
            temp.push_back(nums[right]);
            right += 1;
        }
        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }

        return cnt;
    }
    int mergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return 0;
        int cnt = 0;
        int mid = low + (high - low) / 2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += merge(nums, low, mid, high);
        return cnt;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

// Brute Force
// TC- O(N*N)
// SC- O(1)
/*
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] > 2 * nums[j])
                    cnt += 1;
            }
        }
        return cnt;
    }
};
*/

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
    cout << sol.reversePairs(nums) << endl;

    return 0;
}