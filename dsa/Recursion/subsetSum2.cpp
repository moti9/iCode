#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void findSubSetSum(int ind, vector<int> nums, vector<vector<int>> &subset, vector<int> ds)
{
    subset.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i > ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        findSubSetSum(i + 1, nums, subset, ds);
        ds.pop_back();
    }
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
    sort(nums.begin(), nums.end());
    vector<int> ds;
    vector<vector<int>> subset;
    findSubSetSum(0, nums, subset, ds);

    for (auto x : subset)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}