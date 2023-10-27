#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    struct Compare
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
        for (auto &list : lists)
        {
            if (list != nullptr)
            {
                pq.push(list);
            }
        }
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next != nullptr)
            {
                pq.push(node->next);
            }
        }
        return head->next;
    }
};

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(6);

    ListNode *list3 = new ListNode(7);
    list3->next = new ListNode(8);
    list3->next->next = new ListNode(9);

    vector<ListNode *> lists = {list1, list2, list3};
    Solution sol;
    ListNode *mergedList = sol.mergeKLists(lists);

    printList(mergedList);

    return 0;
}