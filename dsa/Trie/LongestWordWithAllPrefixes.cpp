#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
    Node *links[26];
    bool flag = false;

public:
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
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

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkPrefixExists(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                if (node->isEnd() == false)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie obj;
    for (auto it : a)
    {
        obj.insert(it);
    }
    string longest = "";
    for (auto it : a)
    {
        if (obj.checkPrefixExists(it))
        {
            if (it.size() > longest.size())
            {
                longest = it;
            }
            else if (it.size() == longest.size() && it < longest)
            {
                longest = it;
            }
        }
    }
    return longest == "" ? "None" : longest;
}

int main()
{
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    cout << completeString(n, str) << endl;

    return 0;
}

/*

TC- O(N)+O(Avg.Len)+O(N*Avg.len)
SC-Can't determine bz it's changes ...
26*26*26*26....

*/