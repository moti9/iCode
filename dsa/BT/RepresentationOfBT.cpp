#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    return 0;
}