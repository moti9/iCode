#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using BFS without making adjacency list
// TC- O(N*N)
// SC- O(N)+O(N)

class Solution
{
public:
    void bfs(int node, vector<vector<int>> &isConnected, vector<int> &visit)
    {
        queue<int> q;
        q.push(node);
        visit[node] = 1;

        while (!q.empty())
        {
            node = q.front();
            q.pop();

            for (int i = 0; i < isConnected.size(); i++)
            {
                if (isConnected[node][i] && !visit[i])
                {
                    visit[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int cnt = 0;
        vector<int> visit(n);

        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                cnt++;
                bfs(i, isConnected, visit);
            }
        }

        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> isConnected[i][j];
        }
    }
    Solution sol;
    cout << sol.findCircleNum(isConnected) << endl;
    return 0;
}