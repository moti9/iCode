#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int maximumCount(vector<int> &nums)
{
    int st = 0;
    int end = nums.size() - 1;
    int pos = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] >= 0)
        {
            pos = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    if (pos < 0 || pos >= nums.size())
    {
        pos = -1;
    }
    int neg = nums.size();
    if (pos != -1)
    {
        pos = nums.size() - pos;
        neg -= pos;
    }
    return max(pos, neg);
}
int maximumCount(vector<int> &nums)
{
    int pos = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
    int n = nums.size();
    int neg = nums.size();
    if (pos >= 0 && pos < nums.size())
    {
        pos = nums.size() - pos;
        neg -= pos;
    }
    return max(pos, neg);
}

int maximumCount(vector<int> &nums)
{
    int pos = 0, neg = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
            pos++;
        else if (nums[i] < 0)
            neg++;
    }
    return max(pos, neg);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << maximumCount(nums) << endl;

    return 0;
}