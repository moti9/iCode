#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;
        ListNode *temp = head;
        while (temp != NULL)
        {
            st.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            if (temp->data != st.top())
            {
                return false;
            }
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(1);

    Solution sol;
    cout << sol.isPalindrome(root) << endl;
    return 0;
}