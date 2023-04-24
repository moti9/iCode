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
        this->data = val;
        this->next = NULL;
    }
};

void insert(Node *&tail, int element, int data)
{
    Node *nodetoinsert = new Node(data);
    Node *temp = tail;
    while (temp->data != element)
    {
        temp = temp->next;
    }
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
    // tail = nodetoinsert;
}

int main()
{
    Node *node1 = new Node(10);
    Node *tail = node1;

    insert(tail, 10, 15);

    cout << node1 << endl;
    cout << tail << endl;

    cout << tail->data << " " << tail->next->data << endl;
    return 0;
}