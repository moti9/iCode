#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
    Node *links[2];

public:
    bool containsKey(int ind)
    {
        return (links[ind] != NULL);
    }

    void put(int ind, Node *node)
    {
        links[ind] = node;
    }
    Node *get(int ind)
    {
        return links[ind];
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxi = maxi | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int m = queries.size();
    vector<pair<int, pair<int, int>>> ofq;
    for (int i = 0; i < m; i++)
    {
        ofq.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(ofq.begin(), ofq.end());
    vector<int> ans(m, -1);
    Trie trie;
    int ind = 0;
    for (int i = 0; i < m; i++)
    {
        int ai = ofq[i].first;
        int xi = ofq[i].second.first;
        int qind = ofq[i].second.second;

        while (ind < n && arr[ind] <= ai)
        {
            trie.insert(arr[ind]);
            ind++;
        }
        if (ind != 0)
            ans[qind] = trie.getMax(xi);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> queries;
    for (int i = 0; i < m; i++)
    {
        int x, a;
        cin >> x >> a;
        queries.push_back({x, a});
    }

    vector<int> ans = maxXorQueries(arr, queries);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}