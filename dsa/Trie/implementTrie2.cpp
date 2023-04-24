#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

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
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    void deleteEnd()
    {
        cntEndWith--;
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPrefix;
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

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getPrefix();
    }

    // Assume that it's guarantee that the word is present
    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            node = node->get(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }

    // If not guarantee
    bool search(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        if (node->getEnd() > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void eraseWord(string &word)
    {
        if (search(word))
        {
            Node *node = root;
            for (int i = 0; i < word.length(); i++)
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            node->deleteEnd();
        }
        else
        {
            return;
        }
    }
};

int main()
{
    Trie *obj = new Trie();
    string st = "moti";
    obj->insert(st);
    obj->insert(st);
    st = "vasu";
    obj->insert(st);
    obj->insert(st);
    cout << obj->countWordsEqualTo(st) << endl;
    st = "moti";
    cout << obj->countWordsEqualTo(st) << endl;
    obj->erase(st);
    cout << obj->countWordsEqualTo(st) << endl;

    return 0;
}