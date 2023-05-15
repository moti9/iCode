#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *rev = new ListNode(-1);
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *temp = new ListNode(curr->val);
            temp->next = rev;
            rev->next = temp;
            curr = curr->next;
        }
        return rev->next;
    }
};

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head;
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);

    Solution sol;
    ListNode *revList = sol.reverseList(head);
    printList(revList);

    return 0;
}