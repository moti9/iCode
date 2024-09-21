#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// struct TreeNode
// {
//     string name;
//     int lockedById;
//     bool isLocked;
//     TreeNode *parent;
//     vector<TreeNode *> children;
//     int lockedDescendantCount; // Reference count for locked descendants

//     TreeNode(string nm, TreeNode *pr)
//     {
//         name = nm;
//         parent = pr;
//         lockedById = -1; // Indicates the node is not locked
//         isLocked = false;
//         lockedDescendantCount = 0; // Count of locked descendants
//     }
// };

// struct MAryTree
// {
//     TreeNode *root;
//     unordered_map<string, TreeNode *> nameNode;

//     MAryTree(const string &name)
//     {
//         root = new TreeNode(name, nullptr);
//         nameNode[name] = root;
//     }

//     void makeTree(const vector<string> &names, int m)
//     {
//         queue<TreeNode *> q;
//         int ind = 1, n = names.size();
//         q.push(root);

//         while (!q.empty())
//         {
//             TreeNode *node = q.front();
//             q.pop();

//             vector<string> childNames;
//             for (int i = 0; i < m && ind < n; ++i, ++ind)
//             {
//                 TreeNode *child = new TreeNode(names[ind], node);
//                 node->children.push_back(child);
//                 nameNode[names[ind]] = child;
//                 q.push(child);
//             }
//         }
//     }

//     void updateParents(TreeNode *node, bool increment)
//     {
//         TreeNode *par = node->parent;
//         while (par)
//         {
//             if (increment)
//                 par->lockedDescendantCount++;
//             else
//                 par->lockedDescendantCount--;
//             par = par->parent;
//         }
//     }

//     bool isLockedAncestors(TreeNode *node)
//     {
//         TreeNode *par = node->parent;
//         while (par)
//         {
//             if (par->isLocked)
//                 return true;
//             par = par->parent;
//         }
//         return false;
//     }

//     // API to Lock a node
//     bool lock(const string &name, int id)
//     {
//         if (nameNode.find(name) == nameNode.end())
//             return false; // Node does not exist
//         TreeNode *node = nameNode[name];
//         if (node->isLocked || node->lockedDescendantCount > 0)
//             return false;

//         // Check ancestors
//         if (isLockedAncestors(node))
//             return false;

//         node->isLocked = true;
//         node->lockedById = id;
//         updateParents(node, true); // Increment count in ancestors
//         return true;
//     }

//     // API to Unlock a node
//     bool unlock(const string &name, int id)
//     {
//         if (nameNode.find(name) == nameNode.end())
//             return false; // Node does not exist
//         TreeNode *node = nameNode[name];
//         if (!node->isLocked || node->lockedById != id)
//             return false;

//         node->isLocked = false;
//         node->lockedById = -1;
//         updateParents(node, false); // Decrement count in ancestors
//         return true;
//     }

//     // API to Upgrade a node
//     bool upgradeLock(const string &name, int id)
//     {
//         if (nameNode.find(name) == nameNode.end())
//             return false; // Node does not exist
//         TreeNode *node = nameNode[name];
//         if (node->isLocked || node->lockedDescendantCount == 0)
//             return false;

//         // Check all locked descendants are locked by the same id
//         queue<TreeNode *> q;
//         q.push(node);
//         while (!q.empty())
//         {
//             TreeNode *cur = q.front();
//             q.pop();

//             for (auto child : cur->children)
//             {
//                 if (child->isLocked && child->lockedById != id)
//                     return false;
//                 if (child->lockedDescendantCount > 0)
//                     q.push(child);
//             }
//         }

//         // Check ancestors
//         if (isLockedAncestors(node))
//             return false;

//         // Unlock all locked descendants
//         q.push(node);
//         while (!q.empty())
//         {
//             TreeNode *cur = q.front();
//             q.pop();

//             for (auto child : cur->children)
//             {
//                 if (child->isLocked)
//                     unlock(child->name, id);
//                 if (child->lockedDescendantCount > 0)
//                     q.push(child);
//             }
//         }

//         // Lock the current node
//         lock(node->name, id);
//         return true;
//     }
// };

class TreeNode
{
public:
    string name;
    int lockedById;
    bool isLocked;
    TreeNode *parent;
    vector<TreeNode *> childs;
    int lockedDescendantCount; // Counter for locked descendants
    int lockedAncestorCount;   // Counter for locked ancestors

    TreeNode(string name_val, TreeNode *new_parent)
        : name(name_val), lockedById(-1), isLocked(false), parent(new_parent),
          lockedDescendantCount(0), lockedAncestorCount(0) {}
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

    bool lock(string name, int id)
    {
        TreeNode *node = nameNode[name];
        if (!node || node->isLocked || node->lockedDescendantCount > 0 || node->lockedAncestorCount > 0)
        {
            return false;
        }

        node->isLocked = true;
        node->lockedById = id;

        // Update locked ancestor counts
        TreeNode *par = node->parent;
        while (par)
        {
            par->lockedDescendantCount++;
            par = par->parent;
        }

        return true;
    }

    bool unlock(string name, int id)
    {
        TreeNode *node = nameNode[name];
        if (!node || !node->isLocked || node->lockedById != id)
        {
            return false;
        }

        node->isLocked = false;
        node->lockedById = -1;

        // Update locked ancestor counts
        TreeNode *par = node->parent;
        while (par)
        {
            par->lockedDescendantCount--;
            par = par->parent;
        }

        return true;
    }

    bool upgradeLock(string name, int id)
    {
        TreeNode *node = nameNode[name];
        if (!node || node->isLocked || node->lockedDescendantCount == 0 || node->lockedAncestorCount > 0)
        {
            return false;
        }

        // Check if all locked descendants are locked by the same id
        queue<TreeNode *> q;
        q.push(node);
        vector<TreeNode *> toUnlock;

        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();

            for (TreeNode *child : cur->childs)
            {
                if (child->isLocked)
                {
                    if (child->lockedById != id)
                    {
                        return false; // Cannot upgrade due to locked descendant with different id
                    }
                    toUnlock.push_back(child);
                }
                if (child->lockedDescendantCount > 0)
                {
                    q.push(child); // Traverse further if there are locked descendants
                }
            }
        }

        // Unlock all locked descendants
        for (TreeNode *desc : toUnlock)
        {
            unlock(desc->name, id);
        }

        // Lock the node itself
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
            cout << (tree->lock(name, id) ? "true" : "false") << "\n";
        }
        else if (opType == 2)
        {
            cout << (tree->unlock(name, id) ? "true" : "false") << "\n";
        }
        else if (opType == 3)
        {
            cout << (tree->upgradeLock(name, id) ? "true" : "false") << "\n";
        }
    }

    delete tree; // Clean up to avoid memory leaks
    return 0;
}
