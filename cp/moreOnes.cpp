#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int> &v, int left, int mid, int right, int &inversions)
{
    std::vector<int> temp(right - left + 1);

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            inversions += (mid - i + 1);
            temp[k++] = v[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = v[i++];
    }

    while (j <= right)
    {
        temp[k++] = v[j++];
    }

    k = 0;
    for (int a = left; a <= right; a++)
    {
        v[a] = temp[k++];
    }
}

void mergeSort(std::vector<int> &v, int left, int right, int &inversions)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(v, left, mid, inversions);
        mergeSort(v, mid + 1, right, inversions);
        merge(v, left, mid, right, inversions);
    }
}

int getSubsCount(std::string &input)
{
    int n = input.length();
    std::vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        nums[i] = input[i] - '0';
        if (nums[i] == 0)
        {
            nums[i] = -1;
        }
    }

    std::vector<int> pref(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        pref[i] = sum;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (pref[i] > 0)
            cnt++;
    }

    std::reverse(pref.begin(), pref.end());
    int inversions = 0;
    mergeSort(pref, 0, n - 1, inversions);
    int ans = cnt + inversions;
    return ans;
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        std::string s;
        std::cin >> s;
        std::cout << getSubsCount(s) << std::endl;
    }
    return 0;
}
