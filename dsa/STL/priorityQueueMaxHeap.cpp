#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

# Def :: In the case of the max heap, priority queues are a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains and the rest elements are in decreasing order.

# The syntax for a max-heap priority queue :: priority_queue<object_type> variable_name;

# Example :: priority_queue<int> pq;

# Functions in priority queue ::

=>  push() – to insert an element in the priority queue.
    pq.push(110);
    pq.push(220);

=>  pop() – deletes the top element of the priority queue.
    pq.pop();

=>  top() – returns the element at the top of the priority queue.
    pq.top();

=>  emplace() – to insert an element in the priority.
    pq.emplace(1);
    pq.emplace(2);

=>  size() – returns the number of elements in the priority queue.
    pq.size();

=>  empty() – to check if the priority queue is empty or not.
    pq.empty();


*/

template <typename T>
void printpriorityqueue(priority_queue<T> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main()
{
    priority_queue<int> pq;
    for (int i = 1; i <= 5; i++)
    {
        pq.push(i);
    }

    cout << "The elements of the priority queue are:" << endl;
    printpriorityqueue(pq);

    cout << "The size of the priority queue: " << pq.size() << endl;
    cout << "The top element of the priority queue: " << pq.top() << endl;
    cout << "Pop the top element: " << endl;
    pq.pop();
    printpriorityqueue(pq);

    return 0;
}
