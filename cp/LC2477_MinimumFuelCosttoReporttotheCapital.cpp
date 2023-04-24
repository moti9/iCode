#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int dfs(int node, int parent, vector<int> graph[], int seats, long long &ans)
    {
        int people = 1;
        for (auto ch : graph[node])
        {
            if (ch == parent)
                continue;
            parent += dfs(ch, node, graph, seats, ans);
        }

        if (node > 0)
            ans += (people + seats - 1) / seats;
        return people;
    }

public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        vector<int> graph[roads.size() + 1];
        for (auto &x : roads)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        long long ans = 0;
        dfs(0, -1, graph, seats, ans);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> roads(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> roads[i][0] >> roads[i][1];
    }
    int seats;
    cin >> seats;

    Solution sol;
    cout << sol.minimumFuelCost(roads, seats) << endl;

    return 0;
}