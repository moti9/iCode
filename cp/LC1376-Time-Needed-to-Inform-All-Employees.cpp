#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using DFS
// TC- O(N)
// SC- O(N)

class Solution
{
    void dfs(int parent, int time, vector<int> adj[], vector<int> &informTime, int &maxTime)
    {
        maxTime = max(maxTime, time);
        for (auto adjn : adj[parent])
        {
            dfs(adjn, time + informTime[parent], adj, informTime, maxTime);
        }
        return;
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                adj[manager[i]].push_back(i);
            }
        }

        int maxTime = 0;
        dfs(headID, 0, adj, informTime, maxTime);
        return maxTime;
    }
};

// Using BFS
// TC- O(N)
// SC- O(N)
/*
class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                adj[manager[i]].push_back(i);
            }
        }

        int maxTime = 0;
        queue<pair<int, int>> q;
        q.push({headID, 0});
        while (!q.empty())
        {
            auto mng_time = q.front();
            q.pop();
            int parent = mng_time.first;
            int time = mng_time.second;
            maxTime = max(maxTime, time);
            for (auto adn : adj[parent])
            {
                q.push({adn, time + informTime[parent]});
            }
        }
        return maxTime;
    }
};
*/

int main()
{
    int n;
    cin >> n;
    int headId;
    cin >> headId;
    vector<int> manager(n), informTime(n);

    for (int i = 0; i < n; i++)
    {
        cin >> manager[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> informTime[i];
    }

    Solution sol;
    cout << sol.numOfMinutes(n, headId, manager, informTime) << endl;

    return 0;
}