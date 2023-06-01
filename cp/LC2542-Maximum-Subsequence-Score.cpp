#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        long long ans = 0;
        int n = nums1.size();
        vector<pair<int, int>> num_pair;
        for (int i = 0; i < n; i++)
        {
            num_pair.push_back({nums2[i], nums1[i]});
        }
        sort(num_pair.rbegin(), num_pair.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for (int i = 0; i < k - 1; i++)
        {
            sum += num_pair[i].second;
            pq.push(num_pair[i].second);
        }
        for (int i = k - 1; i < n; i++)
        {
            sum += num_pair[i].second;
            pq.push(num_pair[i].second);
            long long temp = sum * (long long)num_pair[i].first;
            ans = max(ans, temp);

            sum -= pq.top();
            pq.pop();
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }
    int k;
    cin >> k;

    Solution sol;

    cout << sol.maxScore(nums1, nums2, k) << endl;

    return 0;
}