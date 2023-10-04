#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Node
{
public:
    int val;
    Node *left, *right;
    Node(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

Node *root = nullptr;

void create(vector<int> arr, int n)
{
    if (n < 1)
        return;
    int i = 0;
    root = new Node(arr[i++]);
    queue<Node *> q;
    q.push(root);
    int maxSum = arr[0];
    int level = 1;
    int ans = 1;
    while (!q.empty())
    {
        if (i >= n)
            return;
        int sz = q.size();
        int curr = 0;
        level++;
        for (int j = 0; j < sz; j++)
        {
            Node *node = q.front();
            q.pop();

            if (i < n - 1)
            {
                node->left = new Node(arr[i++]);
                q.push(node->left);
                curr += node->val;
            }
            else
            {
                break;
            }
            if (i < n - 1)
            {
                node->right = new Node(arr[i++]);
                q.push(node->right);
                curr += node->val;
            }
            else
            {
                break;
            }
        }
        if (curr >= maxSum)
        {
            maxSum = curr;
            ans = level;
        }
    }
    cout << ans << "\n";
}

void printTreeLevelOrder(Node *root)
{
    if (!root)
    {
        return;
    }

    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        int sz = queue.size();
        for (int i = 0; i < sz; i++)
        {
            Node *current_node = queue.front();
            queue.pop();

            cout << current_node->val << " ";

            if (current_node->left)
            {
                queue.push(current_node->left);
            }

            if (current_node->right)
            {
                queue.push(current_node->right);
            }
        }
        cout << endl;
    }
}

void findMaxiInLevel(vector<int> &arr, int n)
{
    int level = 1;
    int i = 0;
    int maxSum = arr[i++];
    int levelEle = 1;
    int ansLevel = 1;
    while (true)
    {
        if (i >= n)
        {
            break;
        }
        level += 1;
        levelEle *= 2;
        int currSum = 0;
        for (int j = 0; j < levelEle; j++)
        {
            if (i < n)
            {
                currSum += arr[i++];
            }
            else
            {
                break;
            }
        }
        if (currSum > maxSum)
        {
            maxSum = currSum;
            ansLevel = level;
        }
    }
    cout << ansLevel << "\n";
}

int main()
{
    vector<int> arr = {
        1,
        2,
        3,
        4,
        6, 7, 8};
    create(arr, 8);
    findMaxiInLevel(arr, 8);

    printTreeLevelOrder(root);
    return 0;
}
