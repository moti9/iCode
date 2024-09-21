#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
public:
    int num;
    int lockedBy;
    bool isLocked;
    Node *parent;
    vector<Node *> children;
    unordered_set<Node *> lockedChild;

    Node(int val, Node *par)
    {
        num = val;
        lockedBy = -1;
        isLocked = false;
        parent = par;
    }
};

class LockingTree
{
    Node *root;
    unordered_map<int, Node *> numNode;

public:
    LockingTree(vector<int> &parent)
    {
        int n = parent.size();
        root = new Node(parent[0], nullptr);
        numNode[parent[0]] = root;

        for (int i = 1; i < n; i++)
        {
            Node *par_node = numNode[parent[i]];
            Node *child = new Node(i, par_node);
            par_node->children.push_back(child);
            numNode[i] = child;
        }
    }

    bool lock(int num, int user)
    {
        Node *root = numNode[num];
        if (!root || root->isLocked || !root->lockedChild.empty())
        {
            return false;
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

        root->isLocked = true;
        root->lockedBy = user;
        par = root->parent;

        while (par)
        {
            par->lockedChild.insert(root);
            par = par->parent;
        }

        return true;
    }

    bool unlock(int num, int user)
    {
        Node *root = numNode[num];
        if (!root || !root->isLocked || root->lockedBy != user)
        {
            return false;
        }

        Node *par = root->parent;
        while (par)
        {
            par->lockedChild.erase(root);
            par = par->parent;
        }
        root->isLocked = false;
        root->lockedBy = -1;
        return true;
    }

    bool upgrade(int num, int user)
    {
        Node *root = numNode[num];
        if (!root || root->isLocked || root->lockedChild.empty())
        {
            return false;
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

        for (Node *ld : root->lockedChild)
        {
            unlock(ld->num, ld->lockedBy);
        }
        lock(root->num, user);
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    // cin>>ttt;
    while (ttt--)
    {
    }
    return 0;
}
/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/