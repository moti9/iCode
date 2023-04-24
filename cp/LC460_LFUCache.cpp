#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct Node
{
    int key, value, ct;
    Node *prev, *next;
    Node(int key, int val)
    {
        this->key = key;
        this->value = val;
        ct = 1;
    }
};

struct List
{
    int size;
    Node *head, *tail;

    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *node)
    {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
        size--;
    }
};

class LFUCache
{
    map<int, Node *> keyNode;
    map<int, List *> freqList;
    int minFreq, currSize, maxSize;

public:
    LFUCache(int capacity)
    {
        maxSize = capacity;
        minFreq = 0, currSize = 0;
    }

    void updateFreqList(Node *node)
    {
        keyNode.erase(node->key);
        freqList[node->ct]->removeNode(node);
        if (node->ct == minFreq && freqList[node->ct]->size == 0)
        {
            minFreq++;
        }
        List *nextHigherFreqList = new List();

        if (freqList.find(node->ct + 1) != freqList.end())
        {
            nextHigherFreqList = freqList[node->ct + 1];
        }
        node->ct += 1;
        nextHigherFreqList->addFront(node);
        freqList[node->ct] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            updateFreqList(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSize == 0)
        {
            return;
        }
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else
        {
            if (currSize == maxSize)
            {
                List *ls = freqList[minFreq];
                keyNode.erase(ls->tail->prev->key);
                freqList[minFreq]->removeNode(ls->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqList.find(minFreq) != freqList.end())
            {
                listFreq = freqList[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqList[minFreq] = listFreq;
        }
    }
};

int main()
{
    LFUCache *lfu;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "LFUCache")
        {
            int cap;
            cin >> cap;
            lfu = new LFUCache(cap);
        }
        else if (s == "put")
        {
            int key, value;
            cin >> key >> value;
            lfu->put(key, value);
        }
        else if (s == "get")
        {
            int key;
            cin >> key;

            cout << lfu->get(key) << endl;
        }
    }

    return 0;
}