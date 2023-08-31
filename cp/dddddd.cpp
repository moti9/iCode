#include <bits/stdc++.h>

using namespace std;

int beauty(int n, int m, string s, int x[], int y[])
{
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> Incoming(n + 1);

    for (int i = 0; i < m; i++)
    {
        graph[x[i]].push_back(y[i]);
        Incoming[y[i]].push_back(x[i]);
    }

    queue<int> q;
    vector<int> inDegree(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (auto it : graph[i])
        {
            inDegree[it]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topSort;
    int maxi = -1;

    while (!q.empty())
    {

        auto curr = q.front();
        q.pop();

        topSort.push_back(curr);

        for (auto i : graph[curr])
        {
            inDegree[i]--;

            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if (topSort.size() != n)
    {
        return maxi;
    }

    vector<vector<int>> dp(n + 1, vector<int>(26, 0));

    for (auto i : topSort)
    {
        if (Incoming[i].size() == 0)
        {
            dp[i][s[i - 1] - 'a'] = 1;
        }
        else
        {
            for (auto it : Incoming[i])
            {
                for (int ch = 0; ch < 26; ch++)
                {
                    dp[i][ch] = max(dp[i][ch], dp[it][ch]);
                }
            }
            dp[i][s[i - 1] - 'a']++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            maxi = max(maxi, dp[i][j]);
        }
    }
    return maxi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;

    int x[m], y[m];

    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> y[i];
    }

    cout << beauty(n, m, s, x, y) << endl;

    return 0;
}

/*
5  8
reeet
4 2 4 2 4 5 3 3
3 5 2 4 2 2 3 4

4 2
2 4
4 2
5 2
3 3
3 4

*/