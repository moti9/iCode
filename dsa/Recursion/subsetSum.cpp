#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void findSubSetSum(int ind, int sum, vector<int> nums, multiset<int> &mst)
{
    if (ind == nums.size())
    {
        mst.insert(sum);
        return;
    }
    // sum += nums[ind];
    findSubSetSum(ind + 1, sum + nums[ind], nums, mst);
    // sum -= nums[ind];
    findSubSetSum(ind + 1, sum, nums, mst);
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
    vector<int> subsetsum;
    multiset<int> mst;
    findSubSetSum(0, 0, nums, mst);

    for (auto it = mst.begin(); it != mst.end(); it++)
    {
        subsetsum.push_back(*it);
    }
    for (auto x : subsetsum)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}