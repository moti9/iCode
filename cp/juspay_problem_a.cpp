#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class TreeNode
{
public:
    string name;
    int lockedById;
    bool isLocked;
    TreeNode *parent;
    vector<TreeNode *> childs;
    unordered_set<TreeNode *> lockedDescendants;

    TreeNode(string nm, TreeNode *pr)
    {
        name = nm;
        parent = pr;
        lockedById = -1;
        isLocked = false;
    }

    void addChild(vector<string> &childNames)
    {
        for (auto &nm : childNames)
        {
            childs.push_back(new TreeNode(nm, this));
        }
    }
};

class MAryTree
{
public:
    TreeNode *root;
    unordered_map<string, TreeNode *> nameNode;

    MAryTree(string name)
    {
        root = new TreeNode(name, nullptr);
        nameNode[name] = root;
    }

    void makeTree(vector<string> &names, int m)
    {
        queue<TreeNode *> q;
        int ind = 1, n = names.size();
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            for (int i = 0; i < m && ind < n; ++i, ++ind)
            {
                TreeNode *child = new TreeNode(names[ind], node);
                node->childs.push_back(child);
                nameNode[names[ind]] = child;
                q.push(child);
            }
        }
    }

    void updateParents(TreeNode *node, bool add_node)
    {
        TreeNode *par = node->parent;
        while (par)
        {
            if (add_node)
            {
                par->lockedDescendants.insert(node);
            }
            else
            {
                par->lockedDescendants.erase(node);
            }
            par = par->parent;
        }
    }

    bool isLockedAncestors(TreeNode *node)
    {
        TreeNode *par = node->parent;
        while (par)
        {
            if (par->isLocked)
                return true;
            par = par->parent;
        }
        return false;
    }

    // API to Lock a node
    bool lock(string name, int id)
    {
        TreeNode *node = nameNode[name];
        if (!node || node->isLocked || !node->lockedDescendants.empty())
        {
            return false;
        }

        // Check ancestors
        if (isLockedAncestors(node))
        {
            return false;
        }

        node->isLocked = true;
        node->lockedById = id;
        updateParents(node, true);
        return true;
    }

    // API to Unlock a node
    bool unlock(string name, int id)
    {
        TreeNode *node = nameNode[name];
        if (!node || !node->isLocked || node->lockedById != id)
            return false;

        node->isLocked = false;
        node->lockedById = -1;
        updateParents(node, false);
        return true;
    }

    // API to Upgrade a node
    bool upgradeLock(string name, int id)
    {
        TreeNode *node = nameNode[name];
        if (!node || node->isLocked || node->lockedDescendants.empty())
            return false;

        // Check all locked descendants are locked by the same id
        for (TreeNode *child : node->lockedDescendants)
        {
            if (child->lockedById != id)
                return false;
        }

        // Check ancestors
        if (isLockedAncestors(node))
        {
            return false;
        }

        // Unlock all locked descendants
        unordered_set<TreeNode *> lockedDescendants = node->lockedDescendants;
        for (TreeNode *descendant : lockedDescendants)
        {
            unlock(descendant->name, id);
        }

        // Lock the current node
        lock(node->name, id);
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
            cout << (tree->lock(name, id) ? "true" : "false");
        }
        else if (opType == 2)
        {
            cout << (tree->unlock(name, id) ? "true" : "false");
        }
        else if (opType == 3)
        {
            cout << (tree->upgradeLock(name, id) ? "true" : "false");
        }
        cout << "\n";
    }

    delete tree;
    return 0;
}
