#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Approach-1
void findPermutations(vector<int> nums, vector<vector<int>> &permute, vector<int> ds, vector<bool> freq)
{
    if (ds.size() == nums.size())
    {
        permute.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        {
            freq[i] = true;
            ds.push_back(nums[i]);
            findPermutations(nums, permute, ds, freq);
            ds.pop_back();
            freq[i] = false;
        }
    }
}

// Approach-2(Optimized Approach)
void findPermutation(int ind, vector<int> nums, vector<vector<int>> &permute)
{
    if (ind == nums.size())
    {
        permute.push_back(nums);
        return;
    }

    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[ind], nums[i]);
        findPermutation(ind + 1, nums, permute);
        swap(nums[ind], nums[i]);
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
    vector<int> ds;
    vector<bool> freq(n);
    vector<vector<int>> permute;
    // findPermutations(nums, permute, ds, freq);
    findPermutation(0,nums, permute);

    for (auto x : permute)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}