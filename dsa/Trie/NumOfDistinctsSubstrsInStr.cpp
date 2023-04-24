#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
    Node *links[26];

public:
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

class Trie
{

public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
};

int countDistinctSubstrings(string &s)
{
    Trie obj;
    int ct = 0;
    for (int i = 0; i < s.size(); i++)
    {
        Node *node = obj.root;
        for (int j = i; j < s.size(); j++)
        {
            if (!node->containsKey(s[j]))
            {
                ct++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }

    //Include null substr
    return ct + 1;
}

int main()
{
    string s;
    cin >> s;
    cout << countDistinctSubstrings(s) << endl;

    return 0;
}