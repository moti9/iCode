#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltParent(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = findUltParent(parent[u]);
        }
        return parent[u];
    }

    void unionByRank(int u, int v)
    {
        int ultpu = findUltParent(u);
        int ultpv = findUltParent(v);
        if (rank[ultpu] < rank[ultpv])
        {
            parent[ultpu] = ultpv;
        }
        else if (rank[ultpv] < rank[ultpu])
        {
            parent[ultpv] = ultpu;
        }
        else
        {
            parent[ultpv] = ultpu;
            rank[ultpu] += 1;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        unordered_map<string, int> mailNode;
        DisjointSet ds(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mailNode.find(mail) != mailNode.end())
                {
                    ds.unionByRank(i, mailNode[mail]);
                }
                else
                {
                    mailNode[mail] = i;
                }
            }
        }

        vector<string> mergeMail[n];
        for (auto it : mailNode)
        {
            string mail = it.first;
            int node = ds.findUltParent(it.second);

            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++)
        {
            if (mergeMail[i].size() == 0)
            {
                continue;
            }
            sort(mergeMail[i].begin(), mergeMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (int j = 0; j < mergeMail[i].size(); j++)
            {
                temp.push_back(mergeMail[i][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++)
        {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++)
            {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++)
            {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]"
             << endl;
    }
}
