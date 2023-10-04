#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

struct TrieNode
{
    TrieNode *children[2];
    int count;

    TrieNode()
    {
        children[0] = children[1] = nullptr;
        count = 0;
    }
};

void insertTrie(TrieNode *root, string &s)
{
    TrieNode *current = root;
    for (char c : s)
    {
        int idx = c - '0';
        if (!current->children[idx])
        {
            current->children[idx] = new TrieNode();
        }
        current = current->children[idx];
        current->count++;
    }
}

long long countDistinctSubsequences(string S)
{
    int n = S.length();
    TrieNode *root = new TrieNode();
    long long result = 0;

    for (int i = 0; i < n; i++)
    {
        string subsequence = S.substr(i);
        insertTrie(root, subsequence);
        result = (result * 2 % MOD + 1 + MOD - root->count) % MOD;
    }

    return result;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string S;
        cin >> S;
        long long result = countDistinctSubsequences(S);
        cout << result << endl;
    }

    return 0;
}
