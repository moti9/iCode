#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *prev = &dummy;
        ListNode *current = head;

        while (current && current->next)
        {
            ListNode *first = current;
            ListNode *second = current->next;

            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = current;
            current = first->next;
        }

        return dummy.next;
    }
};

// Recursive
/*
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newHead = head->next;

        head->next = swapPairs(newHead->next);
        newHead->next = head;

        return newHead;
    }
};
*/

// With swapping value
/*
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *curr = head;
        while (curr && curr->next)
        {
            int temp = curr->val;
            curr->val = curr->next->val;
            curr->next->val = temp;
            curr = curr->next->next;
        }
        return head;
    }
};
*/

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
    ListNode *head = new ListNode{1};
    head->next = new ListNode{2};
    head->next->next = new ListNode{3};
    head->next->next->next = new ListNode{4};
    head->next->next->next->next = new ListNode{5};

    Solution sol;
    ListNode *ans = sol.swapPairs(head);

    printList(ans);

    return 0;
}