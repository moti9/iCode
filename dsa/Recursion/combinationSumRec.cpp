#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void findCombinations(int ind, int n, int target, vector<int> nums, vector<vector<int>> &comb, vector<int> ds)
{
    if (ind == n)
    {
        if (target == 0)
        {
            comb.push_back(ds);
        }
        return;
    }
    if (nums[ind] <= target)
    {
        ds.push_back(nums[ind]);
        findCombinations(ind, n, target - nums[ind], nums, comb, ds);
        ds.pop_back();
    }
    findCombinations(ind + 1, n, target, nums, comb, ds);
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
    int k;
    cin >> k;
    vector<vector<int>> comb;
    vector<int> ds;
    findCombinations(0, n, k, nums, comb, ds);
    for (auto x : comb)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}