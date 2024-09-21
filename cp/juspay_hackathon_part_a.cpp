#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

Problem statement
You are given a complete, balanced M-Ary Tree and must support Q queries.
There are 3 kinds of queries. Return true or false depending on whether the query was successful.

1. Lock(v, id) - Lock vertex v for user - id
2. Unlock(v, id) - If vertex v is locked by the same id, unlock it.
3. Upgrade(v, id) - If v is unlocked and has at least one locked vertex in it's subtree and every
locked vertex in the subtree of v is locked by id, unlock them and lock v instead.

Further, here are some additional constraints

A vertex cannot be locked if it has any locked ancestors or descendants, by any ID.
When a vertex is upgraded, it's locked descendants are automatically unlocked.
An upgrade operation is not possible if the vertex is already locked or has any locked ancestors
An unlock operation is only possible if the vertex is already locked and locked by the same id


*/

class TreeNode
{
public:
    string name;
    int lockedById;
    bool isLocked;
    TreeNode *parent;
    vector<TreeNode *> childs;
    unordered_set<TreeNode *> lockedDescendents;

    TreeNode(string name_val, TreeNode *new_parent)
    {
        name = name_val;
        lockedById = -1;
        isLocked = false;
        parent = new_parent;
    }
};

class MAryTree
{
public:
    TreeNode *root;
    unordered_map<string, TreeNode *> nameNode;
    mutex mtx;
    MAryTree(string name)
    {
        root = new TreeNode(name, nullptr);
        nameNode[name] = root;
    }

    void makeTree(vector<string> &names, int m)
    {
        int index = 1, n = names.size();
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            for (int i = 0; i < m && index < n; i++, index++)
            {
                TreeNode *new_node = new TreeNode(names[index], node);
                nameNode[names[index]] = new_node;
                node->childs.push_back(new_node);
                q.push(new_node);
            }
        }
    }

    bool lockNodeId(string name, int id)
    {
        lock_guard<mutex> lock(mtx);

        TreeNode *root = nameNode[name];
        if (!root)
        {
            return false;
        }

        if (root->isLocked || !root->lockedDescendents.empty())
        {
            return false;
        }

        TreeNode *par = root->parent;
        while (par)
        {
            if (par->isLocked)
            {
                return false;
            }
            par = par->parent;
        }

        root->lockedById = id;
        root->isLocked = true;

        par = root->parent;
        while (par)
        {
            par->lockedDescendents.insert(root);
            par = par->parent;
        }

        return true;
    }

    bool unlockNodeId(string name, int id)
    {
        lock_guard<mutex> lock(mtx);

        TreeNode *root = nameNode[name];
        if (!root)
        {
            return false;
        }

        if (!root->isLocked || root->lockedById != id)
        {
            return false;
        }

        root->lockedById = -1;
        root->isLocked = false;

        TreeNode *par = root->parent;
        while (par)
        {
            par->lockedDescendents.erase(root);
            par = par->parent;
        }
        return true;
    }

    bool upgradeNodeId(string name, int id)
    {
        lock_guard<mutex> lock(mtx);

        TreeNode *root = nameNode[name];
        if (!root)
        {
            return false;
        }

        if (root->isLocked || root->lockedDescendents.empty())
        {
            return false;
        }

        for (TreeNode *child : root->lockedDescendents)
        {
            if (child->lockedById != id)
                return false;
        }

        TreeNode *par = root->parent;
        while (par)
        {
            if (par->isLocked)
            {
                return false;
            }
            par = par->parent;
        }

        unordered_set<TreeNode *> stt = root->lockedDescendents;
        for (TreeNode *ld : stt)
        {
            unlockNodeId(ld->name, id);
        }

        lockNodeId(root->name, id);
        return true;
    }
};

int main()
{
    int n, m, t;
    cin >> n >> m >> t;

    vector<string> names(n);
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }
    MAryTree *tree = new MAryTree(names[0]);
    tree->makeTree(names, m);

    while (t--)
    {
        string name;
        int opType, id;
        cin >> opType >> name >> id;

        if (opType == 1)
        {
            cout << ((tree->lockNodeId(name, id)) ? "true" : "false");
        }
        else if (opType == 2)
        {
            cout << ((tree->unlockNodeId(name, id)) ? "true" : "false");
        }
        else if (opType == 3)
        {
            cout << ((tree->upgradeNodeId(name, id)) ? "true" : "false");
        }
        cout << "\n";
    }

    return 0;
}

