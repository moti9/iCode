#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

# Def :: Double Ended Queue which is also called Deque is a type of queue data structure in which the insertion and deletion of elements can be either in front or rear.

# Syntax :: deque<object_type> variable_name;

# Example ::
    deque<int> dq;
    deque<string> dq;

# Functions in Deque ::

=>  push_back() – to insert an element at the end of the deque.
    deque<int> dq;
    dq.push_back(110);
    dq.push_back(220);

=>  push_front() – to insert an element at the front of the deque.
    deque<int> dq;
    dq.push_front(110);
    dq.push_front(220);

=>  pop_back() – deletes the last element of the deque.
    dq.pop_back();

=>  pop_front() – deletes the front element of the deque.
    dq.pop_front();

=>  front() – it gives a reference to the first element of the deque.
    dq.front();

=>  back() – it gives a reference to the last element of the deque.
    dq.back();

=>  size() – returns the number of elements on the deque.
    dq.size();

=>  empty() – to check if the deque is empty or not.
    dq.empty();

*/

template <typename T>
void printdeque(deque<T> dq)
{
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);
    dq.push_front(50);

    cout << "The elements in the deque are: ";
    printdeque(dq);

    cout << "The size of the deque is: " << dq.size() << endl;

    cout << "The first element in the deque: " << dq.front() << endl;
    cout << "Deleting the first element" << endl;
    dq.pop_front();
    printdeque(dq);
    
    cout << "The last element of the deque: " << dq.back() << endl;
    cout << "Deleting the last element" << endl;
    dq.pop_back();
    printdeque(dq);

    return 0;
}