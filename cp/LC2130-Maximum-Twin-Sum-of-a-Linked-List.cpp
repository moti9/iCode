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

// Reverse Second Half In Place
// TC- O(N)
// SC- O(1)

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL;
        while (slow)
        {
            ListNode *nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        int maxi = 0;
        ListNode *start = head;
        while (prev)
        {
            int sum = start->val + prev->val;
            maxi = max(maxi, sum);
            start = start->next;
            prev = prev->next;
        }
        return maxi;
    }
};

// Brute Force Approach
// TC- O(N)
// SC- O(N)
/*
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        vector<int> nums;
        ListNode *curr = head;
        while (curr)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        int maxi = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            maxi = max(maxi, sum);
            i += 1;
            j -= 1;
        }
        return maxi;
    }
};
*/

int main()
{
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    Solution sol;
    cout << sol.pairSum(head) << endl;

    return 0;
}