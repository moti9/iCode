#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int reach = 0;
    for (int i = 0; i < n; i++)
    {
        if (reach < i)
            return false;
        reach = max(reach, i + nums[i]);
    }
    return true;
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
    cout << canJump(nums) << endl;

    return 0;
}