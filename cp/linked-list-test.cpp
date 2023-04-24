#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    Node *root = new Node(0);
    Node *temp = root;
    while (n--)
    {
        int val;
        cin >> val;
        temp->next = new Node(val);
        temp = temp->next;
    }
    printList(root->next);

    return 0;
}