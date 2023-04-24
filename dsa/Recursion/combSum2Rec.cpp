#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


//Modified version of combination sum 1
void findCombinations(int ind, int target, vector<int> nums, set<vector<int>> &st, vector<int> ds)
{
    if (ind == nums.size())
    {
        if (target == 0)
        {
            st.insert(ds);
        }
        return;
    }
    if (nums[ind] > target)
    {
        return;
    }
    ds.push_back(nums[ind]);
    findCombinations(ind + 1, target - nums[ind], nums, st, ds);
    ds.pop_back();
    findCombinations(ind + 1, target, nums, st, ds);
}

//Optimized Approach
void findCombination(int ind, int target, vector<int> nums, vector<vector<int>> &comb, vector<int> ds)
{
    if (target == 0)
    {
        comb.push_back(ds);
        return;
    }

    for (int i = ind; i < nums.size(); i++)
    {
        if (i > ind && nums[i] == nums[i - 1])
            continue;
        if (nums[i] > target)
            break;

        ds.push_back(nums[i]);
        findCombination(i + 1, target - nums[i], nums, comb, ds);
        ds.pop_back();
    }
}

void printComb(vector<vector<int>> comb)
{
    for (auto x : comb)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
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
    int target;
    cin >> target;

    sort(nums.begin(), nums.end());

    vector<int> ds;
    vector<vector<int>> comb;
    findCombination(0, target, nums, comb, ds);
    printComb(comb);
    comb.clear();

    set<vector<int>> st;
    findCombinations(0, target, nums, st, ds);

    for (auto it = st.begin(); it != st.end(); it++)
    {
        comb.push_back(*it);
    }
    printComb(comb);

    return 0;
}