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
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie obj;
    for (int i = 0; i < n; i++)
    {
        obj.insert(arr1[i]);
    }
    int maxi = 0;
    for (int i = 0; i < m; i++)
    {
        int temp = obj.getMax(arr2[i]);
        maxi = max(maxi, temp);
    }
    return maxi;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    cout << maxXOR(n, m, arr1, arr2) << endl;

    return 0;
}