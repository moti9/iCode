#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// PreOrder-(Root-Left-Right)
void preOrder(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    // Root
    cout << head->data << " ";
    // Left
    preOrder(head->left);
    // Right
    preOrder(head->right);
}

// Using stack
vector<int> preOrderItr(Node *head)
{
    vector<int> pre;
    if (head == NULL)
    {
        return pre;
    }
    stack<Node *> st;
    st.push(head);
    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();
        pre.push_back(node->data);
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    return pre;
}

// Using Queue
/*
vector<int> preOrderItr2(Node *head)
{
    vector<int> pre;
    if (head == NULL)
    {
        return pre;
    }
    queue<Node *> q;
    q.push(head);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        pre.push_back(node->data);
        if (node->left)
            q.push(node->left);
        else
            q.push(node->right);
    }
    return pre;
}
*/

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    vector<int> pre = preOrderItr(root);
    for (auto x : pre)
        cout << x << " ";
    cout << endl;

    // vector<int> pre2 = preOrderItr(root);
    // for (auto x : pre2)
    //     cout << x << " ";
    // cout << endl;

    preOrder(root);

    return 0;
}