#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*
void rev(vector<int> &nums, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    swap(nums[l], nums[r]);
    rev(nums, l + 1, r - 1);
}
*/
void rev(int nums[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    swap(nums[l], nums[r]);
    rev(nums, l + 1, r - 1);
}

int main()
{
    int n;
    cin >> n;
    // vector<int> nums(n);
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    rev(nums, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}