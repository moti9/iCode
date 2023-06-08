#include <bits/stdc++.h>
using namespace std;

// O(N*M*4log(N*M))
// O(N*M)
class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1)
            {
                return effort;
            }

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                {
                    continue;
                }

                int neff = max(effort, abs(heights[nrow][ncol] - heights[r][c]));
                if (neff < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = neff;
                    pq.push({neff, {nrow, ncol}});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> heights;

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < m; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }

        Solution obj;
        cout << obj.MinimumEffort(heights) << "\n";
    }
    return 0;
}
