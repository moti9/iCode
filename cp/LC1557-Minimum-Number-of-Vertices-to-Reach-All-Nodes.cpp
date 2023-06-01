#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// In-Degree Count
// TC- O(N+E)
// SC- O(N)

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> hasParent(n);
        for (auto e : edges)
        {
            hasParent[e[1]] = true;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!hasParent[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution sol;
    vector<int> ans = sol.findSmallestSetOfVertices(n, edges);
    for (auto a : ans)
        cout << a << " ";
    cout << "\n";

    return 0;
}