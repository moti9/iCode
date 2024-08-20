#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
public:
    int val;
    int index;
    Node *parent, *left, *right;

    Node()
    {
        val = 0;
        index = 0;
        parent = left = right = nullptr;
    }
};

vector<Node *> arr;
vector<int> pNode(65536);
int pi = 0;

Node *make_tree(Node *u, int i, int n)
{
    if (i > n)
        return nullptr;

    Node *node = new Node();
    node->val = pNode[pi++];
    node->parent = u;
    arr.push_back(node);

    node->left = make_tree(node, (2 * i), n);
    node->right = make_tree(node, 2 * i + 1, n);

    return node;
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
    }
    pi = 0;
    arr.clear();

    for (int i = 0; i < n; i++)
    {
        cin >> pNode[i];
    }

    make_tree(nullptr, 1, n);

    set<int> in_ord;
    for (int i = 0; i < n; i++)
    {
        arr[i]->index = i;
        if ((arr[i]->parent) && ((arr[i]->parent->val) != (arr[i]->val / 2)))
            in_ord.insert(i);
    }

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;

        --x, --y;

        auto itr_x = in_ord.find(x);
        if (itr_x != in_ord.end())
            in_ord.erase(itr_x);
        auto itr_y = in_ord.find(y);
        if (itr_y != in_ord.end())
            in_ord.erase(itr_y);

        if (arr[x]->left != nullptr)
        {
            auto itr_xl = in_ord.find(arr[x]->left->index);
            if (itr_xl != in_ord.end())
                in_ord.erase(itr_xl);
        }
        if (arr[x]->right != nullptr)
        {
            auto itr_xr = in_ord.find(arr[x]->right->index);
            if (itr_xr != in_ord.end())
                in_ord.erase(itr_xr);
        }

        if (arr[y]->left != nullptr)
        {
            auto itr_yl = in_ord.find(arr[y]->left->index);
            if (itr_yl != in_ord.end())
                in_ord.erase(itr_yl);
        }
        if (arr[y]->right != nullptr)
        {
            auto itr_yr = in_ord.find(arr[y]->right->index);
            if (itr_yr != in_ord.end())
                in_ord.erase(itr_yr);
        }

        Node *xp = arr[x]->parent;
        Node *xl = arr[x]->left;
        Node *xr = arr[x]->right;

        Node *yp = arr[y]->parent;
        Node *yl = arr[y]->left;
        Node *yr = arr[y]->right;

        if (xp)
        {
            if (arr[x] == xp->left)
                xp->left = arr[y];
            else
                xp->right = arr[y];
        }

        if (yp)
        {
            if (arr[y] == yp->left)
                yp->left = arr[x];
            else
                yp->right = arr[x];
        }

        // Swapping children only if they exist
        if (xl)
            xl->parent = arr[y];
        if (xr)
            xr->parent = arr[y];

        if (yl)
            yl->parent = arr[x];
        if (yr)
            yr->parent = arr[x];

        swap(arr[x]->left, arr[y]->left);
        swap(arr[x]->right, arr[y]->right);
        swap(arr[x]->parent, arr[y]->parent);
        swap(arr[x]->index, arr[y]->index);
        swap(arr[x], arr[y]);

        if ((arr[x]->parent) && ((arr[x]->parent->val) != (arr[x]->val / 2)))
            in_ord.insert(arr[x]->index);
        if ((arr[y]->parent) && ((arr[y]->parent->val) != (arr[y]->val / 2)))
            in_ord.insert(arr[y]->index);

        if (arr[x]->left && (arr[x]->left->parent) && ((arr[x]->left->parent->val) != (arr[x]->left->val / 2)))
            in_ord.insert(arr[x]->left->index);
        if (arr[y]->left && (arr[y]->left->parent) && ((arr[y]->left->parent->val) != (arr[y]->left->val / 2)))
            in_ord.insert(arr[y]->left->index);

        if (arr[x]->right && (arr[x]->right->parent) && ((arr[x]->right->parent->val) != (arr[x]->right->val / 2)))
            in_ord.insert(arr[x]->right->index);
        if (arr[y]->right && (arr[y]->right->parent) && ((arr[y]->right->parent->val) != (arr[y]->right->val / 2)))
            in_ord.insert(arr[y]->right->index);

        if (in_ord.size() == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solve();
    }
    return 0;
}
