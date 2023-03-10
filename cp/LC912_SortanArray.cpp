#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void merge(vector<int> &arr, int left, int mid, int right, vector<int> &tempArr)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int s1 = left, s2 = mid + 1;
        for (int i = 0; i < n1; i++)
        {
            tempArr[s1 + i] = arr[s1 + i];
        }
        for (int i = 0; i < n2; i++)
        {
            tempArr[s2 + i] = arr[s2 + i];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (tempArr[s1 + i] <= tempArr[s2 + j])
            {
                arr[k] = tempArr[s1 + i];
                i += 1;
            }
            else
            {
                arr[k] = tempArr[s2 + j];
                j += 1;
            }
            k += 1;
        }
        while (i < n1)
        {
            arr[k] = tempArr[s1 + i];
            i += 1;
            k += 1;
        }
        while (j < n2)
        {
            arr[k] = tempArr[s2 + j];
            j += 1;
            k += 1;
        }
    }

    void mergeSort(vector<int> &arr, int left, int right, vector<int> &tempArr)
    {
        if (left >= right)
        {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, tempArr);
        mergeSort(arr, mid + 1, right, tempArr);

        merge(arr, left, mid, right, tempArr);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> tempArr(n);
        mergeSort(nums, 0, n - 1, tempArr);

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
    vector<int> sortedArr = sol.sortArray(nums);

    for (auto s : sortedArr)
        cout << s << " ";
    cout << endl;

    cout << is_sorted(nums.begin(), nums.end()) << endl;

    return 0;
}