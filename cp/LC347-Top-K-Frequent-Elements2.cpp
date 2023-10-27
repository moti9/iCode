#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (k == nums.size())
            return nums;
        unordered_map<int, int> ump;
        for (auto &num : nums)
            ump[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto &x : ump)
        {
            pq.push({x.second, x.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

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

    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);
    for (auto &ans : result)
        cout << ans << " ";
    cout << endl;

    return 0;
}