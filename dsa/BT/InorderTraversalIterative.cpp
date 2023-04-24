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

// Inorder-(Left-Root-Right)
void inOrder(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    // Left
    inOrder(head->left);
    // Root
    cout << head->data << " ";
    // Right
    inOrder(head->right);
}

// Using Stack
vector<int> inOrderItr(Node *head)
{
    vector<int> ino;
    if (head == NULL)
    {
        return ino;
    }
    stack<Node *> st;
    while (true)
    {
        if (head)
        {
            st.push(head);
            head = head->left;
        }
        else
        {
            if (st.empty())
                break;
            head = st.top();
            ino.push_back(head->data);
            st.pop();
            head = head->right;
        }
    }
    return ino;
}

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

    vector<int> ino = inOrderItr(root);
    for (auto x : ino)
        cout << x << " ";
    cout << endl;

    inOrder(root);

    return 0;
}