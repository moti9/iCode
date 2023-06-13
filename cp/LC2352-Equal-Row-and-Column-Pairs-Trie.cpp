#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(N*N)
// SC- O(N*N)

class TrieNode
{
public:
    int cnt;
    unordered_map<int, TrieNode *> children;

    TrieNode()
    {
        cnt = 0;
    }
};

class Trie
{
    TrieNode *trie;

public:
    Trie()
    {
        trie = new TrieNode();
    }
    void insert(vector<int> &arr)
    {
        TrieNode *myTrie = trie;
        for (auto a : arr)
        {
            if (myTrie->children.find(a) == myTrie->children.end())
            {
                myTrie->children[a] = new TrieNode();
            }
            myTrie = myTrie->children[a];
        }
        myTrie->cnt += 1;
    }

    int search(vector<int> &arr)
    {
        TrieNode *myTrie = trie;
        for (auto a : arr)
        {
            if (myTrie->children.find(a) != myTrie->children.end())
            {
                myTrie = myTrie->children[a];
            }
            else
            {
                return 0;
            }
        }
        return myTrie->cnt;
    }
};

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();

        Trie *myTrie = new Trie();
        for (auto row : grid)
        {
            myTrie->insert(row);
        }

        int cnt = 0;
        for (int row = 0; row < n; row++)
        {
            vector<int> colArr(n);
            for (int col = 0; col < n; col++)
            {
                colArr[col] = grid[col][row];
            }
            cnt += myTrie->search(colArr);
        }
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.equalPairs(grid) << endl;

    return 0;
}