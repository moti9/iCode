#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> graph;
        for (auto &edge : adjacentPairs)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int root = 0;
        for (auto &pr : graph)
        {
            if (pr.second.size() == 1)
            {
                root = pr.first;
                break;
            }
        }
        vector<int> nums = {root};
        int prev = INT_MAX;
        while (nums.size() < graph.size())
        {
            for (auto &nb : graph[root])
            {
                if (nb != prev)
                {
                    nums.push_back(nb);
                    prev = root;
                    root = nb;
                    break;
                }
            }
        }
        return nums;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adjPairs;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adjPairs.push_back({x, y});
    }

    Solution sol;
    vector<int> nums = sol.restoreArray(adjPairs);
    for (auto &num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}