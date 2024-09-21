
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string name;
    int lockedUserId;
    bool isLocked;
    Node *parent;
    int countLock;

    vector<Node *> childs;
    unordered_set<Node *> lockedChild;

    Node(string new_name, Node *new_parent)
    {
        name = new_name;
        lockedUserId = -1;
        isLocked = false;
        parent = new_parent;
        countLock = 0;
    }
};

class MAryTree
{
public:
    Node *root;
    unordered_map<string, Node *> nameNode;

    MAryTree(string name)
    {
        root = new Node(name, nullptr);
        nameNode[name] = root;
    }

    void createMAryTree(vector<string> &names, int m)
    {
        int n = names.size(), index = 1;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            vector<string> new_nodes;
            for (int i = 0; i < m && index < n; i++, index++)
            {
                Node *nnode = new Node(names[index], node);
                nameNode[names[index]] = nnode;
                node->childs.push_back(nnode);
                q.push(nnode);
            }
        }
    }

    bool lockNodeId(string name, int id)
    {
        Node *root = nameNode[name];
        if (!root)
            return false;

        // update the countLock
        root->countLock++;

        // validate the conditions
        if (root->countLock > 1 || root->isLocked || !root->lockedChild.empty())
        {
            root->countLock--;
            return false;
        }

        Node *par = root->parent;
        while (par)
        {
            // update the lockedChild
            par->lockedChild.insert(root);

            // validate the conditions
            if (par->countLock > 0 || par->isLocked || root->lockedChild.size() > 0)
            {
                // rollback the chnages
                // need to remove the root from the lockedChild
                Node *curr_par = root->parent;
                while (curr_par != par)
                {
                    curr_par->lockedChild.erase(root);
                    curr_par = curr_par->parent;
                }
                // remove from the parent
                par->lockedChild.erase(root);
                root->countLock--;
                return false;
            }
            par = par->parent;
        }

        root->lockedUserId = id;
        root->isLocked = true;

        // release the lock
        root->countLock--;

        return true;
    }

    // bool lockNodeId(string name, int id)
    // {
    //     Node *root = nameNode[name];
    //     if (!root)
    //         return false;

    //     // update the countLock
    //     root->countLock++;

    //     // validate the conditions
    //     if (root->countLock > 1 || root->isLocked || !root->lockedChild.empty())
    //     {
    //         root->countLock--;
    //         return false;
    //     }

    //     Node *par = root->parent;
    //     while (par)
    //     {
    //         // update the lockedChild
    //         par->lockedChild.insert(root);

    //         // validate the conditions
    //         if (par->countLock > 0 || par->isLocked || root->lockedChild.size() > 0 || root->countLock > 1)
    //         {
    //             // rollback the chnages
    //             // remove from the parent
    //             par->lockedChild.erase(root);
    //             root->countLock--;
    //             // need to remove the root from the lockedChild
    //             Node *curr_par = root->parent;
    //             while (curr_par != par)
    //             {
    //                 curr_par->lockedChild.erase(root);
    //                 curr_par = curr_par->parent;
    //             }
    //             return false;
    //         }

    //         par = par->parent;
    //     }
    //     // validate for inconsistency(expected value is 1)
    //     if (root->countLock > 1)
    //     {
    //         root->countLock--;
    //         par = root->parent;
    //         while (par)
    //         {
    //             par->lockedChild.erase(root);
    //             par = par->parent;
    //         }
    //         return false;
    //     }
    //     root->lockedUserId = id;
    //     root->isLocked = true;
    //     root->countLock--;

    //     return true;
    // }

    bool unlockNodeId(string name, int id)
    {
        Node *root = nameNode[name];
        if (!root)
            return false;

        root->countLock++;

        if (root->countLock > 1 || !root->isLocked || root->lockedUserId != id)
        {
            root->countLock--;
            return false;
        }

        Node *par = root->parent;
        while (par)
        {
            par->lockedChild.erase(root);
            
            if (par->countLock > 0 || par->isLocked || root->lockedChild.size() > 0)
            {
                Node *curr_par = root->parent;
                while (curr_par != par)
                {
                    curr_par->lockedChild.insert(root);
                    curr_par = curr_par->parent;
                }
                par->lockedChild.insert(root);
                root->countLock--;
                return false;
            }
            par = par->parent;
        }

        root->lockedUserId = -1;
        root->isLocked = false;

        root->countLock--;

        return true;
    }

    bool upgradeNodeId(string name, int id)
    {
        Node *root = nameNode[name];
        if (!root)
            return false;

        if (root->isLocked || root->lockedChild.empty())
        {
            return false;
        }

        for (Node *ld : root->lockedChild)
        {
            if (ld->lockedUserId != id)
            {
                return false;
            }
        }

        Node *par = root->parent;
        while (par)
        {
            if (par->isLocked)
            {
                return false;
            }
            par = par->parent;
        }

        unordered_set<Node *> lockedDesc = root->lockedChild;
        for (Node *desc : lockedDesc)
        {
            unlockNodeId(desc->name, id);
        }

        lockNodeId(root->name, id);
        return true;
    }
};

int main()
{

    int n, m, q;
    cin >> n >> m >> q;

    vector<string> names(n);
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    MAryTree *mtree = new MAryTree(names[0]);
    mtree->createMAryTree(names, m);

    while (q--)
    {
        int ops, userId;
        string name;

        cin >> ops >> name >> userId;

        if (ops == 1)
        {
            cout << ((mtree->lockNodeId(name, userId)) ? "true" : "false");
        }
        else if (ops == 2)
        {
            cout << ((mtree->unlockNodeId(name, userId)) ? "true" : "false");
        }
        else
        {
            cout << ((mtree->upgradeNodeId(name, userId)) ? "true" : "false");
        }
        cout << "\n";
    }

    return 0;
}