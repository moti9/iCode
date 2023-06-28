#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
# Def :: A list in STL is a contiguous container that allows the inserting and erasing of elements in constant time and iterating in both directions.

# Syntax :: list<object_type> variable_name;

# Example ::
    list<int> li;
    list<string> li;

# Functions in List ::

=>  push_back() – to insert an element at the end of the list.
    list<int> li;
    li.push_back(110);
    li.push_back(220);

=>  push_front() – to insert an element at the front of the list.
    list<int> li;
    li.push_front(110);
    li.push_front(220);

=>  pop_back() – deletes the last element of the list.
    li.pop_back();

=>  pop_front() – deletes the front element of the list.
    li.pop_front();

=>  front() – it gives a reference to the first element of the list.
    li.front();

=>  back() – it gives a reference to the last element of the list.
    li.back();

=>  reverse() – reverse the list.
    li.reverse();

=>  sort() – sorts the list in ascending order.
    li.sort();

=>  size() – returns the number of elements on the list.
    li.size();

=>  empty() – to check if the list is empty or not.
    li.empty();

# Other functions of the list ::

=>  begin() – it refers to the first element of the list.
=>  end() – it refers to the theoretical element after the last element of the list.
=>  cbegin() – it refers to the first element of the list.
=>  cend() – it refers to the theoretical element after the last element of the list.
=>  rbegin() – it points to the last element of the list.
=>  rend() – it points to the theoretical element before the first element of the list.
=>  emplace_front() – to insert an element at the front of the list.
=>  emplace_back() – to insert an element at the end of the list.
=>  max_size() – the maximum elements a list can hold.
=>  clear() – to delete all the elements of the list.
=>  erase() – to delete a single element or elements between a particular range.

*/

template <typename T>
void printlist(list<T> &ls)
{
    for (auto it = ls.begin(); it != ls.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> ls;
    ls.push_back(10);
    ls.push_back(20);
    ls.push_front(30);
    ls.push_front(40);
    ls.push_front(50);

    cout << "The elements in the list are: ";
    printlist(ls);

    cout << "Reversing the list: ";
    ls.reverse();
    printlist(ls);

    cout << "Sorting the list: ";
    ls.sort();
    printlist(ls);

    cout << "The size of the list is: " << ls.size() << endl;

    cout << "The first element in the list: " << ls.front() << endl;
    cout << "Deleting the first element" << endl;
    ls.pop_front();
    printlist(ls);

    cout << "The last element of the list: " << ls.back() << endl;
    cout << "Deleting the last element" << endl;
    ls.pop_back();
    printlist(ls);

    return 0;
}