#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n), ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans[nums[i] - 1] = nums[nums[i] - 1];
    }
    for (auto x : ans)
        cout << x << " ";

    return 0;
}