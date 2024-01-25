#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void sortedInsert(stack<int> &st, int ele)
{
    if (st.empty() || ele > st.top())
    {
        st.push(ele);
    }
    else
    {
        int top_ele = st.top();
        st.pop();
        sortedInsert(st, ele);
        st.push(top_ele);
    }
}

void sortStack(stack<int> &st)
{
    if (!st.empty())
    {
        int top = st.top();
        st.pop();
        sortStack(st);
        sortedInsert(st, top);
    }
}

void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    int n;
    cin >> n;

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    sortStack(st);
    printStack(st);
    return 0;
}