#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<int> searchRange(vector<int> &nums, int target)
{
    int f = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int s = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    cout << f << " " << s << endl;
    if (f >= 0 && f < nums.size())
    {
        if (nums[f] != target)
        {
            f = -1;
        }
    }
    else
    {
        f = -1;
    }
    if (s >= 0 && s <= nums.size())
    {
        if (nums[s - 1] == target)
        {
            s = s - 1;
        }
        else
        {
            s = -1;
        }
    }
    else
    {
        s = -1;
    }
    return {f, s};
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
    int target;
    cin >> target;
    vector<int> ans = searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}