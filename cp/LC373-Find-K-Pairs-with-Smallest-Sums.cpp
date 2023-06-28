#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        set<pair<int, int>> vis;

        while (k-- && !pq.empty())
        {
            auto pr = pq.top();
            pq.pop();
            int i = pr.second.first, j = pr.second.second;
            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < n && !vis.count({i + 1, j}))
            {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                vis.insert(i + 1, j);
            }
            if (j + 1 < m && !vis.count({i, j + 1}))
            {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                vis.insert(i, j + 1);
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 1; i < n; i++)
    {
        cin >> nums1[i];
    }

    int m;
    cin >> m;
    vector<int> nums2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }

    int k;
    cin >> k;

    Solution sol;

    vector<vector<int>> ans = sol.kSmallestPairs(nums1, nums2, k);

    for (auto &a : ans)
    {
        cout << a[0] << " " << a[1] << endl;
    }

    return 0;
}