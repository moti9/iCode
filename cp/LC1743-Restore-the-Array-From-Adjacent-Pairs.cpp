#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void dfs(int node, int prev, unordered_map<int, vector<int>> &graph, vector<int> &nums)
    {
        nums.push_back(node);
        for (auto &nb : graph[node])
        {
            if (nb != prev)
            {
                dfs(nb, node, graph, nums);
            }
        }
    }

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
        vector<int> nums;
        dfs(root, INT_MAX, graph, nums);
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