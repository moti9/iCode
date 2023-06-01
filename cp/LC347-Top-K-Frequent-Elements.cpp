#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// BetterApproach
//  TC- O(NlogN)
//  SC- O(N)

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] += 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // Max heap---a..b..c[a>b>c]
        for (auto m : mp)
        {
            pq.push({m.second, m.first});
            while (pq.size() > k)
            {
                pq.pop();
            }
        }

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// Brute force
//  TC- O(NlogN)
//  SC- O(N)
/*
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] += 1;
        }
        vector<pair<int, int>> arr;
        for (auto m : mp)
        {
            arr.push_back({m.second, m.first});
        }
        sort(arr.rbegin(), arr.rend());
        for (int i = 0; i < arr.size() && i < k; i++)
        {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
*/

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

    vector<int> ans = sol.topKFrequent(nums, k);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}